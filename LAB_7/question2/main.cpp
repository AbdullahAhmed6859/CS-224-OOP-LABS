#include <iostream>
#include "Time.h"
using std::cin;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int hh, mm, ss;
    cin >> hh >> mm >> ss;
    Time t1(hh, mm, ss); //t1(hh, mm, ss)
    cin >> hh >> mm >> ss;
    Time t2(hh, mm, ss);
    Time t3;
    t3 = t1 + t2; //adding two times should produce a valid time, overflowed hours/minutes/seconds should be adjusted.
    // e.g. adding 18:10:20 with 10:20:30 results in 4:30:50

    t1.show();
    t2.show();
    t3.show();
    return 0;
}
