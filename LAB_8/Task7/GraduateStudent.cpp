#include "GraduateStudent.h"
#include <string>
#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent() : thesisTitle("") {}

GraduateStudent::GraduateStudent(const string &name, const int age, const int stdID, const string &thesisTitle) :
Student(name, age, stdID),
thesisTitle(thesisTitle) {
    cout << "GraduateStudent constructor" << endl;
}

GraduateStudent::~GraduateStudent() {
    cout << "GraduateStudent Destructor" << endl;
}

void GraduateStudent::printGraduateDetails() {
    printStudent();
    cout << "thesisTitle: " << thesisTitle << endl;
}