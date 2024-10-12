#include "Complex.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;
using std::abs;

Complex::Complex() {
    real = 0;
    imag = 0;
}

Complex::Complex(const int r, const int i) {
    real = r;
    imag = i;
}

int Complex::getImag() const {
    return imag;
}

int Complex::getReal() const {
    return real;
}

void Complex::setImag(const int i) {
    imag = i;
}

void Complex::setReal(const int i) {
    real = i;
}

Complex Complex::operator-(const Complex& c2) const {
    return {real - c2.real, imag - c2.imag};
}

Complex Complex::operator-(const int d2) const {\
    return { real - d2, imag};
}

Complex Complex::operator+(const Complex& c2) const {
    return {real + c2.real, imag + c2.imag};
}

Complex Complex::operator+(const int d2) const {
    return {real + d2, imag};
}

Complex Complex::operator*(const Complex& c2) const {
    return {real * c2.real - imag * c2.imag,
        real * c2.imag + imag * c2.real};
}

Complex Complex::operator*(const int d2) const {
    return {real * d2, imag * d2};
}

ostream& Complex::show(ostream& out) const{
    if (imag < 0)
        out << real << " - " << abs(imag) << 'i';
    else
        out << real << " + " << imag << 'i';

    return out;
}

istream& Complex::input(istream& in) {
    in >> real >> imag;
    return in;
}
