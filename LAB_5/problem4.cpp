#include <iostream>
#include <string>
using namespace std;
class Time12 {
    int hours;
    int minutes;
    int seconds;
    char period;
    char seperator;
    
    string addZeros(int num) const {
        if (num >= 10) 
            return to_string(num);
        else 
            return "0" + to_string(num);
    }
    
    public:
    Time12(int ihours, int iminutes, int iseconds, char iperiod, char iseperator) {
        hours = ihours;
        minutes = iminutes;
        seconds = iseconds;
        period = iperiod;
        seperator = iseperator;
    }
    
    Time12(int ihours, int iminutes, int iseconds, char iperiod) {
        hours = ihours;
        minutes = iminutes;
        seconds = iseconds;
        period = iperiod;
        seperator = ':';
    }
    Time12(int ihours, int iminutes, int iseconds) {
        hours = ihours;
        minutes = iminutes;
        seconds = iseconds;
        period = 'A';
        seperator = ':';
    }
    Time12(int ihours, int iminutes) {
        hours = ihours;
        minutes = iminutes;
        seconds = 0;
        period = 'A';
        seperator = ':';
    }
    Time12(int ihours) {
        hours = ihours;
        minutes = 0;
        seconds = 0;
        period = 'A';
        seperator = ':';
    }
    Time12() {
        hours = 12;
        minutes = 0;
        seconds = 0;
        period = 'A';
        seperator = ':';
    }
    
    void show() const {
        cout << hours << seperator << addZeros(minutes) << seperator << addZeros(seconds) << period << 'M' << endl;
    }
    
};


// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//     return 0;
// }


int main(){
    Time12 t1;
    Time12 t2(7);
    Time12 t3(10, 34);
    Time12 t4(12, 2, 10);
    const Time12 t5(10, 30, 0, 'A');
    const Time12 t6(10, 10, 10, 'P', '-');
    
    t1.show();
    t2.show();
    t3.show();
    t4.show();
    t5.show();
    t6.show();
    return 0;
}