#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() {
    stdID = 0;
}
Student::Student(const string &name, const int age, const int stdID) 
    : Person(name, age), stdID(stdID)
{}

void Student::setStudentID(const int id) {
    stdID = id;
}

void Student::printStudent() {
    printPerson();
    cout << "StudentID: " << stdID << endl;
}