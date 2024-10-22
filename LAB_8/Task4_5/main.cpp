#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    Student s1("TEST", 18, 4321);
    Student s;
    s.setName("Abdullah");
    s.setAge(19);
    s.setStudentID(1234);

    s1.printStudent();
    s.printStudent();
    return 0;
}