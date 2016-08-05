/*
*  Author: 	        Gregory Smith
*  File: 		    problem_1.c
*  Last Modified:   02/27/2016	 		
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <assert.h>

volatile int CS = 0;
long runTimeMs;
int threadCount;
volatile int * ENTERING;
volatile int * NUMBER;
volatile long * iterations;

void lock(int i){
	int max = 0;
	int j;
	int current;
	
	ENTERING[i] = 1;

	// find max
	for(j = 0; j < threadCount; j++){
		current = NUMBER[j];
		if(current > max){
			max = current;
		}
	}
	NUMBER[i] = 1 + max;

	ENTERING[i] = 0;

	for(j = 0; j < threadCount; ++j){
		if(j != i){
			// wait until thread j receives its number
			while(ENTERING[j] == 1){/* do nothing */}
			// wait until all threads with smaller numbers, OR with the same
			// number but with higher priority, finish their work
			while((NUMBER[j] != 0) && (NUMBER[j] < NUMBER[i] || (NUMBER[j] == NUMBER[i] && j < i ))){
				/* do nothing */
			}
		}
	}
}

void unlock(int i){
	NUMBER[i] = 0;
}

void * bake_stuff(void * threadID){
	int * tid = (int*)threadID;
	long timeStarted = (long)time(NULL);
	long currentTime = 0;

	
	// Critical Section
	currentTime = time(NULL);
	if(currentTime < 0){
		printf("Error with time(). Exiting program\n");
		exit(-1);
	}
	while(currentTime < (runTimeMs + timeStarted)){
		lock(*tid);
		
		assert(CS==0);
		CS++;
		assert(CS==1);
		CS++;
		assert(CS==2);
		CS++;
		assert(CS==3);
		CS = 0;

		unlock(*tid);
		
		iterations[*tid]++;
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
	int * eyes;
	
	if(argc != 3){
		printf("Error: %s requires 2 integer arguments\n", *argv);
		exit(-1);
	}
	
	// Initialize
	threadCount = atoi(argv[1]);
	runTimeMs = atoi(argv[2]);
	// threads array
	pthreads = malloc(sizeof(pthread_t) * threadCount);	
	// Initialize Lamport's arrays
	ENTERING = (int *)malloc(sizeof(int) * threadCount);
	NUMBER = (int *)malloc(sizeof(int) * threadCount);
	iterations = (long *)malloc(sizeof(int) * threadCount);
	if(ENTERING == NULL || NUMBER == NULL || iterations == NULL){
		printf("Error with malloc(). Exiting program\n");
		exit(-1);
	}
	for(i = 0; i < threadCount; i++){
		ENTERING[i] = 0;
		NUMBER[i] = 0;
		iterations[i] = 0;
	}
	
	// Create the threads
	eyes = (int *)malloc(sizeof(int) * threadCount);
	if(eyes == NULL){
		printf("Error with malloc(). Exiting program\n");
		exit(-1);
	}
	for(i = 0; i < threadCount; i++){
		eyes[i] = i;
		returnCode = pthread_create(&pthreads[i], NULL, bake_stuff, (void *)&eyes[i]);
		if(returnCode){
			printf("ERROR: pthread_create returned %d. Exiting program\n", returnCode);
			exit(-1);
		}
	}

	// wait for threads to finish before exiting main thread
	for(j = 0; j < threadCount; j++){
		pthread_join(pthreads[j], NULL);
		printf("Thread %d entered critical section %ld times\n", j, iterations[j]);
	}

	return 0;
}