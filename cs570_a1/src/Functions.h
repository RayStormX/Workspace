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
    sem_init(&sem_lock, 0, 1);

    pthread_t thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9 ,thread10;
    pthread_create(&thread1, NULL, &doSomething1, NULL);
    pthread_create(&thread2, NULL, &doSomething1, NULL);
    pthread_create(&thread3, NULL, &doSomething1, NULL);
    pthread_create(&thread4, NULL, &doSomething1, NULL);
    pthread_create(&thread5, NULL, &doSomething1, NULL);
    pthread_create(&thread6, NULL, &doSomething1, NULL);
    pthread_create(&thread7, NULL, &doSomething1, NULL);
    pthread_create(&thread8, NULL, &doSomething1, NULL);
    pthread_create(&thread9, NULL, &doSomething1, NULL);
    pthread_create(&thread10, NULL, &doSomething1, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);
    pthread_join(thread8, NULL);
    pthread_join(thread9, NULL);
    pthread_join(thread10, NULL);

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
    cout << "Thread < " << threadId << " > has left lock\n";
}

void *doSomething1(void*) {
    // thread A
	unsigned int tid = (unsigned int)pthread_self();
	//cout << "Thread < " << tid << " > is running\n";
    something(tid);
    return 0;
}

