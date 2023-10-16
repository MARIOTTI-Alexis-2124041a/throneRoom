//
// Created by alexis on 16/10/23.
//
#include <iostream>
#include <thread>
#include <semaphore>
#include "./globals.h"

using namespace std;

class King {
private:
    void answerFavor(){
        cout << "King : Ta faveur est exaucé" << endl;
    }
public:


    [[noreturn]] void administerTheCourt(){
        while (true) {
            subject.acquire();
            king.release();

            this->answerFavor();

            subjectDone.acquire();
            kingDone.release();
            this_thread::sleep_for(1s);
        }
    }
};
