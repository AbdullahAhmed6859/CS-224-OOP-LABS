#ifndef CALCULATOR_H
#define CALCULATOR_H
// #include "calculator.tpp"

template <typename T> class Calculator {
public:
    static T add(T a, T b);
    static T subtract(T a, T b);
    static T multiply(T a, T b);
    static T divide(T a, T b);
    static double average(T a, T b);
};

#endif