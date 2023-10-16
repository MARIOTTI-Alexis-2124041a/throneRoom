//
// Created by alexis on 16/10/23.
//
#include <iostream>
#include <thread>
#include <semaphore>
#include "./globals.cpp"

using namespace std;

class King {
    void answerFavor(){
        cout << "Ta faveur est exaucé" << endl;
    }
public:

    King(){}

    void administerTheCourt(){
        subject.acquire();
        king.release();

        this->answerFavor();

        subjectDone.acquire();
        kingDone.release();
    }
};
