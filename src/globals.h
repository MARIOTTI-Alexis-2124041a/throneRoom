#pragma once

#include <semaphore>

using namespace std;

//This file is used to group all the globals variables of the project

extern unsigned n;
extern unsigned subjects;
extern binary_semaphore queueMutex;
extern binary_semaphore king;
extern binary_semaphore subject;
extern binary_semaphore kingDone;
extern binary_semaphore subjectDone;