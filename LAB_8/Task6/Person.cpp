#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

Person::Person() : name(""), age(0) {
    name = "";
    age = 0;
}

Person::Person(const string &name, const int age) : name(name), age(age) {
}

void Person::setName(const string &n) {
    name = n;
}

void Person::setAge(const int a) {
    age = a;
}

void Person::printPerson() {
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
}