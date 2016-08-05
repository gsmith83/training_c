/*
*  Author: 	        Gregory Smith
*  File: 			problem_5.c
*  Last Modified:   03/04/2016	 		
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
volatile long * iterations;

struct spin_lock_t{
    volatile int threadID;
    volatile int lastPos;
};

struct spin_lock_t * lock;

/*
 * atomic_xadd
 *
 * equivalent to atomic execution of this code:
 *
 * return (*ptr)++;
 * 
 */
static inline int atomic_xadd (volatile int *ptr)
{
  register int val __asm__("eax") = 1;
  asm volatile ("lock xaddl %0,%1"
  : "+r" (val)
  : "m" (*ptr)
  : "memory"
  );  
  return val;
}

void spin_lock(struct spin_lock_t * s){
    int nextThread = atomic_xadd(&(s->lastPos));
    // Spin while other threads are being processed, until
    //  this thread's turn
    while(nextThread != s->threadID){
        /* do nothing */
    }
}

void spin_unlock(struct spin_lock_t * s){
    atomic_xadd(&(s->threadID));
}

void * bake_stuff(void * threadID){
	int * tid = (int*)threadID;
	long timeStarted = (long)time(NULL);
	long currentTime = 0;

	
	currentTime = time(NULL);
	if(currentTime < 0){
		printf("Error with time(). Exiting program\n");
		exit(-1);
	}
    
    // Critical Section
	while(currentTime < (runTimeMs + timeStarted)){
        
        spin_lock(lock);
        
		assert(CS==0);
		CS++;
		assert(CS==1);
		CS++;
		assert(CS==2);
		CS++;
		assert(CS==3);
		CS = 0;
		
		iterations[*tid]++;
        
        spin_unlock(lock);
        
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
    lock = (struct spin_lock_t *)malloc(sizeof(struct spin_lock_t));
    lock->threadID = 0;
    lock->lastPos = 0;
    
	// threads and thread iteration arrays
	pthreads = malloc(sizeof(pthread_t) * threadCount);	
	iterations = (long *)malloc(sizeof(int) * threadCount);
    
	if(iterations == NULL){
		printf("Error with malloc(). Exiting program\n");
		exit(-1);
	}
	for(i = 0; i < threadCount; i++){
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