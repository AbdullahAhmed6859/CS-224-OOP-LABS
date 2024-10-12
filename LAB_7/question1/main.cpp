#include <iostream>
#include "Complex.h"
using namespace std;

ostream& operator<< (ostream& out, const Complex& number) {
    return number.show(out);
}

istream& operator>> (istream& in, Complex& number) {
    return number.input(in);
}

int main() {
    Complex a, b;
    cin >> a;
    cin >> b;
    cout << b - a << endl;
    cout << a + b << endl;
    cout << a * b << endl;
    return 0;
}
