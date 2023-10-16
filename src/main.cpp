#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include "King.cpp"
#include "Subject.cpp"
#include "globals.h"
#include <curses.h>

using namespace std;

//function used for add a new subject into the throne room
void addSubject(unsigned subjectNumber){
    cout << "creation sujet numéro" << subjectNumber << endl;
    Subject sub = Subject(subjectNumber);
    sub.joinTheQueue();
}

int main() {

    King charlesV = King(); //this is the king represented by a King object

    vector<thread> subjectsVector; //vector of threads, used to easily manipulate all the subjects threads

    thread adminCourt(&King::administerTheCourt, &charlesV);

    unsigned numberOfSubjects = 0;
    for (int i = 0; i < 150; i++) {
        subjectsVector.emplace_back(&addSubject, numberOfSubjects);
        numberOfSubjects += 1;
    }

    for (auto &s: subjectsVector) {
        s.join();
    }

    this_thread::sleep_for(10s);

    thread lateMan(&addSubject, numberOfSubjects);

    lateMan.join();
    adminCourt.detach();
    return 0;
}
