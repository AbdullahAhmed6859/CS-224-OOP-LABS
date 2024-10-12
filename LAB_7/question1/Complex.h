#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using std::ostream;
using std::istream;
class Complex {
    int real;
    int imag;

public:
    Complex();

    Complex(int r, int i);

    void setReal(int r);

    void setImag(int i);

    int getReal() const;

    int getImag() const;

    Complex operator-(const Complex& c2) const;

    Complex operator-(int d2) const;

    Complex operator+(const Complex& c2) const;

    Complex operator+(int d2) const;

    Complex operator*(const Complex& c2) const;

    Complex operator*(int d2) const;

    ostream& show(ostream& out) const;

    istream &input(istream &in);

};

#endif
