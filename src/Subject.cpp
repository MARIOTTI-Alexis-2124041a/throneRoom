#include <iostream>
#include "globals.h"

class Subject {
    public:

    unsigned subjectNumber;

    Subject(unsigned subjectNum) : subjectNumber(subjectNum){}

    void joinTheQueue() {
        queueMutex.acquire();
        if (subjects == n) {
            queueMutex.release();
            balk();
        }
        else {
            subjects ++;
            queueMutex.release();
            subject.release();
            king.acquire();
            askQuestion();
            subjectDone.release();
            kingDone.acquire();
            queueMutex.acquire();
            subjects --;
            queueMutex.release();
        }
    }

    private:
    void balk() {
        std::cout << "Subject : Goodbye, i'm "<< subjectNumber << std::endl;
    }

    void askQuestion() {
        std::cout<<"Subject : The subject " << subjectNumber << " ask a question to the king." << std::endl;
    }
};