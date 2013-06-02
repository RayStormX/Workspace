/* Keith Burgess, Raymond Fernandez
 * masc, masc
 * CS570, Spring 2013
 * Assignment #1:
 * Filename: Functions.h
 */

#include<iostream>
#include<string>
#include<fstream>
#include <pthread.h>
#define NUM_THREADS	5

using namespace std;

// writing on a text file

void *printFileInt(void *threadid) {
	long tid;
	tid = (long)threadid;
	ofstream myfile;
	myfile.open ("PROCTAB.txt");
    myfile << threadid << " test\n";
    myfile.close();
}

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}

void *runThreads(){
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
}
