#ifndef KING_H
#define KING_H

#include <iostream>
#include <thread>
#include <semaphore>
#include "./globals.h"

using namespace std;

class King {
private:
    void answerFavor();

    King(){

    }
protected:
    King* instance = nullptr;

public:

    static King* getInstance();

    [[noreturn]] void administerTheCourt();
};

#endif // KING_H