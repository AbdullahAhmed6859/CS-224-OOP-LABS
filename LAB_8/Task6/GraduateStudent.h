#include "Student.h"
#ifndef GRADUATE_STUDENT_H
#define GRADUATE_STUDENT_H

class GraduateStudent : public Student{
    string thesisTitle;
public:
    GraduateStudent();
    GraduateStudent(const string &name, const int age, const int stdID, const string &thesisTitle);
    void printGraduateDetails();
};
#endif