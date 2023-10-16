#pragma once

#include <semaphore>

using namespace std;

extern unsigned n;
extern unsigned subjects;
extern binary_semaphore queueMutex;
extern binary_semaphore king;
extern binary_semaphore subject;
extern binary_semaphore kingDone;
extern binary_semaphore subjectDone;