#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include "King.h"
#include "Subject.cpp"

using namespace std;

//function used for add a new subject into the throne room
void addSubject(unsigned subjectNumber){
    cout << "creation sujet numéro" << subjectNumber << endl;
    Subject sub = Subject(subjectNumber);
    sub.joinTheQueue();
}

int main() {

    King* charlesV = King::getInstance(); //this is the king represented by a King object

    vector<thread> subjectsVector; //vector of threads, used to easily manipulate all the subjects threads

    thread adminCourt(&King::administerTheCourt, std::ref(charlesV)); //starting the main method of the king into a new thread. This method contain an infinite loop

    // filling the vector of subjects
    unsigned numberOfSubjects = 0;
    for (unsigned i = 0; i < 150; ++i) {
        subjectsVector.emplace_back(&addSubject, numberOfSubjects);
        numberOfSubjects += 1;
    }

    // rendezvouses of subjects threads
    for (auto &s: subjectsVector) {
        s.join();
    }

    //generate a late  subject to verify if king is still working
    this_thread::sleep_for(10s);
    thread lateMan(&addSubject, numberOfSubjects);
    lateMan.join();

    adminCourt.detach(); //terminate the king infinite loop thread
    return 0;
}
