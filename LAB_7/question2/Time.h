#ifndef TIME_H
#define TIME_H


class Time{
    int hours, minutes, seconds;
public:
    Time();
    Time(int h);
    Time(int h, int m);
    Time(int h, int m, int s);
    Time operator+(const Time& t) const;
    void show() const;
};




#endif //TIME_H
