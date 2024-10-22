#include <string>
#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person {
    string name;
    int age;
public:
    Person();
    Person(const string& name, const int age);
    void setName(const string& n);
    void setAge(const int a);
    void printPerson();
};

#endif