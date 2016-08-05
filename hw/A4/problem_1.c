/*
*   Author: 	    Gregory Smith
*   File: 			problem_1.c
*   Last Modified:  03/22/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

typedef struct mon_struct_t{
    int cats;
    int birds;
    int dogs;
    long cat_play;
    long dog_play;
    long bird_play;
    pthread_cond_t cat_cv;
    pthread_cond_t bird_cv;
    pthread_cond_t dog_cv;
    pthread_mutex_t lock;
}mon_struct;


long runTime = 10;
mon_struct monitor;
int n_cats, n_dogs, n_birds;

void play(void){
    for (int i=0; i<8; i++) {
        assert(monitor.cats >= 0 && monitor.cats <= n_cats);
        assert(monitor.dogs >= 0 && monitor.dogs <= n_dogs);
        assert(monitor.birds >= 0 && monitor.birds <= n_birds);
        assert(monitor.cats == 0 || monitor.dogs == 0);
        assert(monitor.cats == 0 || monitor.birds == 0);
   }
}

void cat_enter(void){
    pthread_mutex_lock(&monitor.lock);
    while(monitor.birds > 0 || monitor.dogs > 0){
        pthread_cond_wait(&monitor.cat_cv, &monitor.lock);
    }
    // critical section - cat has entered the playground
    monitor.cats++;
    monitor.cat_play++;
    play();
    pthread_mutex_unlock(&monitor.lock);
}

void cat_exit(void){
    pthread_mutex_lock(&monitor.lock);
    // critical section - cat has left the playground
    monitor.cats--;
    if(monitor.cats == 0){
        pthread_cond_broadcast(&monitor.dog_cv);
        pthread_cond_broadcast(&monitor.bird_cv);
    }
    pthread_mutex_unlock(&monitor.lock);
}

void dog_enter(void){
    pthread_mutex_lock(&monitor.lock);
    while(monitor.cats > 0){
        pthread_cond_wait(&monitor.dog_cv, &monitor.lock);
    }
    // critical section
    monitor.dogs++;
    monitor.dog_play++;
    play();
    pthread_mutex_unlock(&monitor.lock);
}

void dog_exit(void){
    pthread_mutex_lock(&monitor.lock);
    //critical section
    monitor.dogs--;
    if(monitor.dogs == 0 && monitor.birds == 0)
        pthread_cond_broadcast(&monitor.cat_cv);
    pthread_mutex_unlock(&monitor.lock);
}

void bird_enter(void){
    pthread_mutex_lock(&monitor.lock);
    while(monitor.cats > 0)
        pthread_cond_wait(&monitor.bird_cv, &monitor.lock);
    //critical section
    monitor.birds++;
    monitor.bird_play++;
    play();
    pthread_mutex_unlock(&monitor.lock);
}

void bird_exit(void){
    pthread_mutex_lock(&monitor.lock);
    //critical section
    monitor.birds--;
    if(monitor.birds == 0 && monitor.dogs == 0)
        pthread_cond_broadcast(&monitor.cat_cv);
    pthread_mutex_unlock(&monitor.lock);
}

void * cat_run(void * arg){
    long timeStarted = (long)time(NULL);
    long currentTime = 0;
    
    currentTime = time(NULL);
    if(currentTime < 0){
        printf("Error with time(). Exiting program\n");
        exit(-1);
    }
    while(currentTime < (timeStarted + runTime)){
        // critical section repeatedly enters and exits the playground for 10 seconds
        cat_enter();
        cat_exit();
        
        currentTime = time(NULL);
        if(currentTime < 0){
            printf("Error with time(). Exiting program\n");
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void * dog_run(void * arg){
    long timeStarted = (long)time(NULL);
    long currentTime = 0;
    
    currentTime = time(NULL);
    if(currentTime < 0){
        printf("Error with time(). Exiting program\n");
        exit(-1);
    }
    while(currentTime < (timeStarted + runTime)){
        // critical section repeatedly enters and exits the playground for 10 seconds
        dog_enter();
        dog_exit();
        
        currentTime = time(NULL);
        if(currentTime < 0){
            printf("Error with time(). Exiting program\n");
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

void * bird_run(void * arg){
    long timeStarted = (long)time(NULL);
    long currentTime = 0;
    
    currentTime = time(NULL);
    if(currentTime < 0){
        printf("Error with time(). Exiting program\n");
        exit(-1);
    }
    while(currentTime < (timeStarted + runTime)){
        // critical section repeatedly enters and exits the playground for 10 seconds
        bird_enter();
        bird_exit();
        
        currentTime = time(NULL);
        if(currentTime < 0){
            printf("Error with time(). Exiting program\n");
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char ** argv){
    pthread_t * cat_threads;
    pthread_t * bird_threads;
    pthread_t * dog_threads;
    int return_code;
    int i, j;
	
	// Command line argument error checking
	if(argc != 4){
		printf("%s requires exactly 3 numerical arguments\n", argv[0]);
		exit(-1);
	}
	
	n_cats = atoi(argv[1]);
	n_dogs = atoi(argv[2]);
	n_birds = atoi(argv[3]);
	
	// Since "0" is valid input, and atoi returns 0 on error, strcmp must be used to determine if input other than "0" was entered
	if((n_cats <= 0 && strcmp(argv[1], "0") != 0) || n_cats > 99 || (n_dogs < 0 && strcmp(argv[2], "0") != 0) || n_dogs > 99 || (n_birds < 0 && strcmp(argv[3], "0") != 0) || n_birds > 99){
		printf("Arguments must be integers between 0 and 99\n");
		exit(-1);
	}
    
    // Initialize struct 
    monitor.cats = 0;
    monitor.birds = 0;
    monitor.dogs = 0;
    monitor.cat_play = 0;
    monitor.bird_play = 0;
    monitor.dog_play = 0;
    if(pthread_mutex_init(&(monitor.lock), NULL) < 0){
        printf("Error with initializing mutex. Exiting program\n");
        exit(-1);
    }
    if(pthread_cond_init(&(monitor.cat_cv), NULL) < 0){
        printf("Error with initializing condition variable. Exiting program\n");
        exit(-1);
    }
    if(pthread_cond_init(&(monitor.bird_cv), NULL) < 0){
        printf("Error with initializing condition variable. Exiting program\n");
        exit(-1);
    }
    if(pthread_cond_init(&(monitor.dog_cv), NULL) < 0){
        printf("Error with initializing condition variable. Exiting program\n");
        exit(-1);
    }
	
	// Create proper number of cat threads
    cat_threads = malloc(sizeof(pthread_t) * n_cats);
	for(i = 0; i < n_cats; i++){
		return_code = pthread_create(&cat_threads[i], NULL, cat_run, NULL);
		if(return_code){
			printf("ERROR: pthread_create returned %d. Exiting program\n", return_code);
			exit(-1);
		}
	}
    // Create proper number of dog threads
    dog_threads = malloc(sizeof(pthread_t) * n_dogs);
	for(i = 0; i < n_dogs; i++){
		return_code = pthread_create(&dog_threads[i], NULL, dog_run, NULL);
		if(return_code){
			printf("ERROR: pthread_create returned %d. Exiting program\n", return_code);
			exit(-1);
		}
	}
    // Create proper number of cat threads
    bird_threads = malloc(sizeof(pthread_t) * n_birds);
	for(i = 0; i < n_birds; i++){
		return_code = pthread_create(&bird_threads[i], NULL, bird_run, NULL);
		if(return_code){
			printf("ERROR: pthread_create returned %d. Exiting program\n", return_code);
			exit(-1);
		}
	}
    
    // wait for threads to finish before exiting main thread
	for(j = 0; j < n_cats; j++){
		pthread_join(cat_threads[j], NULL);
	}
    for(j = 0; j < n_dogs; j++){
		pthread_join(dog_threads[j], NULL);
	}
    for(j = 0; j < n_birds; j++){
		pthread_join(bird_threads[j], NULL);
	}
    
    printf("Cat play = %ld, Dog play = %ld, Bird play = %ld\n", monitor.cat_play, monitor.dog_play, monitor.bird_play);
    return 0;
}