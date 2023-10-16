//
// Created by alexis on 16/10/23.
//
#include <iostream>
#include <thread>
#include <semaphore>
#include "./globals.h"

using namespace std;


//Singleton class used to represent The King
class King {
private:
    void answerFavor(){
        cout << "King : Ta faveur est exaucé" << endl;
    }

    King(){

    }
protected:
    static King* instance;

public:


    King *getInstance();

    void administerTheCourt();
};

//the delcarations of publics methods are out of the class because this is a singleton.

King* King::instance = nullptr;

King *King::getInstance(){
    if (King::instance == nullptr){
        King::instance = new King();
    }
    return instance;
}

void King::administerTheCourt(){
    while (true) {
        subject.acquire();
        king.release();

        this->answerFavor();

        subjectDone.acquire();
        kingDone.release();
        this_thread::sleep_for(1s);
    }
}