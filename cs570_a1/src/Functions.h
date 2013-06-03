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
#define NUM_THREADS	5

void *doSomething(void*);
void *something(char*);
void *doSomething1(void*);
void *doSomething2(void*);
void *doSomething3(void*);

//pthread_t thread1, thread2, thread3;

using namespace std;

sem_t sem_lock; //define semaphore object

int createThreads(){

	// initialize semaphore to 2b
	sem_t sem_lock; //define semaphore object
    sem_init(&sem_lock, 0, 1);

    pthread_t thread1, thread2, thread3;
    cout << "test";
    pthread_create(&thread1, NULL, &doSomething1, NULL);
    pthread_create(&thread2, NULL, &doSomething2, NULL);
    pthread_create(&thread3, NULL, &doSomething3, NULL);
    cout << "test";
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}

int sem_init(sem_t *sem, int pshared, unsigned int value);//initialize semaphore object

// writing on a text file

void printFileInt(int threadid) {
	long tid;
	tid = (long)threadid;
	ofstream myfile;
	myfile.open ("PROCTAB.txt");
    myfile << threadid << " test\n";
    myfile.close();
}


/*void *runThreads(){
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	for(t=0;t<NUM_THREADS;t++){
	     printf("In main process: creating thread %ld\n", t);

	     rc = pthread_create(&threads[t], NULL, printFileInt, (void *)t);
	     if (rc){
	       printf("ERROR; return code from pthread_create() is %d\n", rc);

	       }
	     }
	   pthread_exit(NULL);
}*/


//void destroy_lock(){
	//sem_destroy(sem_lock);
//}

void *doSomething(void*) {
    // thread A
	unsigned int tid = (unsigned int)pthread_self();
    printf("PID of this p: %u\n", tid);
    return 0;
}

void something(char c) {
	cout << "test";
    int i, time;
    for (i = 0; i < 3; i++) {

        // P operation
        if (sem_wait(&sem_lock) == 0) {

            // generate random amount of time (< 30 seconds)
            time = (int) ((double) rand() / RAND_MAX * 10);
        	//unsigned int tid = (unsigned int)pthread_self();
        	//printf("PID of this process: %u\n", tid);
            printf("Thread %c enters and sleeps for %d seconds...\n", c, time);

            sleep(time);

            printf("Thread %c leaves the critical section\n", c);

            // V operation
            sem_post(&sem_lock);
        }
    }
}

void *doSomething1(void*) {
    // thread A
	cout << "test";
    something('A');
    return 0;
}

void *doSomething2(void*) {
    // thread B

    something('B');
    return 0;
}

void *doSomething3(void*) {
    // thread C

    something('C');
    return 0;
}

