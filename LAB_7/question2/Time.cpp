#include "Time.h"

#include <iostream>
using std::cout;
using std::endl;

Time::Time() : hours(0), minutes(0), seconds(0) {
}

Time::Time(const int h) {
    hours = h % 24;
    minutes = 0;
    seconds = 0;
}

Time::Time(int h, int m) {
    h += m / 60;
    m %= 60;
    h %= 24;

    hours = h;
    minutes = m;
    seconds = 0;
}

Time::Time(int h, int m, int s) {
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
    h %= 24;

    hours = h;
    minutes = m;
    seconds = s;
}

Time Time::operator+(const Time& t) const {
    const int s = seconds + t.seconds;
    const int m = minutes + t.minutes + s / 60;
    const int h = hours + t.hours + m / 60;
    return { h % 24, m % 60, s % 60 };
}

void Time::show() const {
    if (hours < 10) cout << "0";
    cout << hours << ":";
    if (minutes < 10) cout << "0";
    cout << minutes << ":";
    if (seconds < 10) cout << "0";
    cout << seconds << endl;
}


