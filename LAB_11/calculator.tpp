#include "calculator.h";
using namespace std;

template <typename T> T Calculator<T>::add(T a, T b) {
    return a + b;
}

template <typename T> T Calculator<T>::subtract(T a, T b) {
    return a - b;
}

template <typename T> T Calculator<T>::multiply(T a, T b) {
    return a * b;
}

template <typename T> T Calculator<T>::divide(T a, T b) {
    return a / b;
}

template <typename T> double Calculator<T>::average(T a, T b) {
    return (a + b) / 2;
}
