/*
*  Author: 	        Gregory Smith
*  File: 			problem_6.c
*  Last Modified:   03/04/2016	 		
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <math.h>

long runTimeMs;
int threadCount;
volatile double circlePoints;
volatile double totalPoints;
pthread_mutex_t * mutex;

// Calculates Pi with the ratio of random points that fall within
//  a unit circle to the total number of points
void * monte_carlo(){
	long timeStarted = (long)time(NULL);
	long currentTime = 0;
    double x;
    double y;
    double distance;
	
	currentTime = time(NULL);
	if(currentTime < 0){
		printf("Error with time(). Exiting program\n");
		exit(-1);
	}
    
    // Run thread for a specified amount of time
	while(currentTime < (runTimeMs + timeStarted)){
        
        // generate random (x,y) point between -.5 and .5 each
        x = (double)rand()/(double)(RAND_MAX/1.0) - 0.5;
        y = (double)rand()/(double)(RAND_MAX/1.0) - 0.5;
        
        if(x < -0.5 || x > 0.5 || y < -0.5 || y > 0.5){
            printf("Error: generated value fell out of range. Exiting program\n");
            exit(-1);
        }
        
        // determine if point is within the circle
        distance = sqrt(pow(x, 2.0) + pow(y, 2.0));
        
        // lock
        if(pthread_mutex_lock(mutex) < 0){
            printf("Error with locking. Exiting program\n");
            exit(-1);
        }
        
        // update ciclePoints and totalPoints
        if(distance <= 0.5)
            circlePoints++;
		
        totalPoints++;
        
        // unlock
        if(pthread_mutex_unlock(mutex) < 0){
            printf("Error with unlocking. Exiting program\n");
            exit(-1);
        }
            
        
		currentTime = time(NULL);
		
		if(currentTime < 0){
			printf("Error with time(). Exiting program\n");
			exit(-1);
		}
	}

	pthread_exit(NULL);
}

int main(int argc, char ** argv){
	pthread_t *pthreads;
	int returnCode;
	int i, j;
    
	if(argc != 3){
		printf("Error: %s requires 2 integer arguments\n", *argv);
		exit(-1);
	}
	
	// Initialize
    circlePoints = 0.0;
    totalPoints = 0.0;
	threadCount = atoi(argv[1]);
	runTimeMs = atoi(argv[2]);
    mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if(pthread_mutex_init(mutex, NULL) < 0){
        printf("Error with initializing mutex. Exiting program\n");
        exit(-1);
    }
    
	// threads and thread iteration arrays
	pthreads = malloc(sizeof(pthread_t) * threadCount);
    
	for(i = 0; i < threadCount; i++){
		returnCode = pthread_create(&pthreads[i], NULL, monte_carlo, NULL);
		if(returnCode){
			printf("ERROR: pthread_create returned %d. Exiting program\n", returnCode);
			exit(-1);
		}
	}

	// wait for threads to finish before exiting main thread
	for(j = 0; j < threadCount; j++){
		pthread_join(pthreads[j], NULL);
	}

    // Calculate and output pi
    printf("Pi = %f\n", (4*circlePoints)/totalPoints);
    
	return 0;
}