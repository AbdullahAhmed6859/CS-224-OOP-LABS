#include "Person.h"
#ifndef STUDENT_H
#define STUDENT_H

class Student: public Person {
    int stdID;
public:
    Student();
    ~Student();
    Student(const string& name, const int age, const int stdID);
    void setStudentID(const int id);
    void printStudent();
};

#endif