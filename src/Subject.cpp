#include <iostream>
#include "globals.cpp"

class Subject {
    public:

    Subject();

    void joinTheQueue() {
        queueMutex.acquire();
        if (subjects == n) {
            queueMutex.release();
            balk();
        }
        else {
            subjects ++;
        }
        queueMutex.release();
        king.acquire();
        askQuestion();
        subjectDone.release();
        kingDone.acquire();
        queueMutex.acquire();
        subjects --;
        queueMutex.release();
    }

    private:
    void balk() {
        std::cout << "Jme tire" << std::endl;
    }

    void askQuestion() {
        std::cout<<"The subject ask a question to the king." << std::endl;
    }
};