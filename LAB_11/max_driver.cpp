#include <iostream>
using namespace std;

template<class T>
T large(T value1, T value2)
{
    return (value1>value2)?value1:value2;
}


int main() {
	cout << large(1, 2) << endl; 
	cout << large("Hello" , "HELLO") << endl; 
	cout << large('d', 'a') << endl; 

    return 0;
}
