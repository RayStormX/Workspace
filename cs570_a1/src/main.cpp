/* Keith Burgess, Raymond Fernandez
 * masc, masc
 * CS570, Spring 2013
 * Assignment #1:
 * Filename: assignment1.cpp
 *
 * Eclipse Notes:
 * 1. properties->c/c++Build->setting->GCC C++ linker->libraries add "pthread" to top
 */

#include<iostream>
#include<string>
#include<fstream>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include"Functions.h"


using namespace std;


int main(int argc, char *argv[])
{
	pthread_t mainThread;
	runThreads();

   /* Last thing that main() should do */
   pthread_exit(NULL);
}
