#include <iostream>
using namespace std;

class Stack {
    int tos;
    unsigned int size;
    int *arr;
    
    public:
    Stack(int length) {
        tos = -1;
        size = length;
        arr = new int[size];
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    int getTos() const {
        return tos;
    }
    unsigned int getSize() const {
        return size;
    }
    int* getArr() const {
        return arr;
    }
    
    void setTos(int newTos) {
        tos = newTos;
    }
    
    void setSize(unsigned int newSize) {
        size = newSize;
    }
    
    void setArr(int* newArr) {
        arr = newArr;
    }
    
    int top() const {
        return tos == -1 ? -1 : arr[tos];
    }
    
    bool isempty() const {
        return tos == -1;
    }
    
    void push(int num) {
        if (tos == size - 1)
            return;
            
        tos++;
        arr[tos] = num;
    }
    
    int pop() {
        if (tos == -1)
            return -1;
            
        int output = arr[tos];
        tos--;
        return output; 
    }
};

int main()
{
    Stack stack1(10);
    
    cout << "Stack1 top is: " << stack1.top() <<endl;
    
    if (stack1.isempty())
    {
        cout << "Stack1 is empty" <<endl;
    }
    else
    {
        cout << "Stack1 is not empty" <<endl;
    }
    
    int nums;
    cin >> nums;
    
    for (int i = 0; i < nums; i++)
    {
        int a;
        cin>>a;
        stack1.push(a);
        cout<<"Pushed "<<a<<" to the Stack1.."<<endl;
    }
    
    cout << "Stack1 top is: " << stack1.top() <<endl;
    
    for (int i = 0; i < nums/2; i++)
    {
        cout << stack1.pop() << " popped from the Stack1."<<endl;
    }
    
    cout << "Stack1 top is: " << stack1.top() << endl;
    
    if (stack1.isempty())
    {
        cout << "Stack1 is empty" <<endl;
    }
    else
    {
        cout << "Stack1 is not empty" <<endl;
    }
    
    for (int i = 0; i < nums/2; i++)
    {
        cout << stack1.pop() << " popped from the Stack1."<<endl;
    }
    
    cout << "Stack1 top is: " << stack1.top() <<endl;
    
    if (stack1.isempty())
    {
        cout << "Stack1 is empty" <<endl;
    }
    else
    {
        cout << "Stack1 is not empty" <<endl;
    }
    
    return 0;
}