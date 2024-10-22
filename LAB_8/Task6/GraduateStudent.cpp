#include "GraduateStudent.h"
#include <string>
#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent() : thesisTitle("") {}

GraduateStudent::GraduateStudent(const string &name, const int age, const int stdID, const string &thesisTitle) :
Student(name, age, stdID),
thesisTitle(thesisTitle) {}

void GraduateStudent::printGraduateDetails() {
    printStudent();
    cout << "thesisTitle: " << thesisTitle << endl;
}