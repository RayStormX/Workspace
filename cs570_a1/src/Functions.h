/* Keith Burgess, Raymond Fernandez
 * masc, masc
 * CS570, Spring 2013
 * Assignment #1:
 * Filename: Functions.h
 */

#include<iostream>
#include<string>
#include<fstream>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define NUM_THREADS	10

void *doSomething(void*);
void *something(char*);
void *doSomething1(void*);
void *doSomething2(void*);
void *doSomething3(void*);

//pthread_t thread1, thread2, thread3;

using namespace std;

sem_t sem_lock; //define global semaphore object

int createThreads(){
	void *status;
	// initialize semaphore
    sem_init(&sem_lock, 0, 1);

    // Array of threads
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	// initialize individual threads in thread array
	for(t=0;t<NUM_THREADS;t++){

		printf("In main process: creating thread %d\n", t);

	    rc = pthread_create(&threads[t], NULL, &doSomething1, (void *)t);

	    if (rc){
	    	printf("ERROR; return code from pthread_create() is %d\n", rc);
	    }
	}

	/*for (int i=0; i<NUM_THREADS; i++) {
		rc = pthread_join(threads[t], &status);
		if (rc) {
			printf("ERROR; return code from pthread_join() is %d\n", rc);
			//exit(-1);
		}
		printf("Main: completed join with thread %ld having a status of %ld\n",t,(long)status);
	}*/

  /* Clean up and exit */
	sem_destroy(&sem_lock);
	pthread_exit(NULL);
    return 0;
}


// writing on a text file
void printFileInt(unsigned int threadid) {
	unsigned int tid = (unsigned int)pthread_self();
	ofstream myfile;
	//string filename = "PROCTAB.txt";
	myfile.open("PROCTAB.txt", ios::out | ios::app );
	cout << "Thread < " << tid << " > is writing to PROCTAB.txt\n";
    myfile << threadid << "\n";
    myfile.close();
}

void something(unsigned int threadId) {

    int time;
    	//cout << "Thread < " << threadId << " > is waiting\n";
        // P operation
        if (sem_wait(&sem_lock) == 0) {

            // generate random amount of time (< 30 seconds)
            time = (int) ((double) rand() / RAND_MAX * 4);
            //cout << "Thread < " << threadId << " > has passed lock\n";
            //printf("Thread %u enters and sleeps for %d seconds...\n", threadId, time);
            printFileInt(threadId);
            sleep(time);

            //printf("Thread %u leaves the critical section\n", threadId);

            // V operation
            sem_post(&sem_lock);
        }
    //cout << "Thread < " << threadId << " > has left lock\n";
}

void *doSomething1(void*) {
	unsigned int tid = (unsigned int)pthread_self();
	//cout << "Thread < " << tid << " > is running\n";
    something(tid);
    return 0;
}

