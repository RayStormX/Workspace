/* Keith Burgess, Raymond Fernandez
 * masc, masc
 * CS570, Spring 2013
 * Assignment #1:
 * Filename: main.cpp
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
#include <semaphore.h>
#include"Functions.h"


using namespace std;


int main() {

	createThreads();

}
