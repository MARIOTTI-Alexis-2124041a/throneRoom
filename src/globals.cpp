//
// Created by alexis on 16/10/23.
//

#include <semaphore>

using namespace std;

unsigned  n = 10;
unsigned  subjects = 0;

binary_semaphore queueMutex(1);
binary_semaphore king(0);
binary_semaphore subject(0);
binary_semaphore kingDone(0);
binary_semaphore subjectDone(0);