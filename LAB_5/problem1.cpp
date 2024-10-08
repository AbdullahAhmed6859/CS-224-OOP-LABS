#include <iostream>
using namespace std;

class Complex {
    double real;
    double imag;
    
    public:
    Complex(double new_real, double new_imag) {
        real = new_real;
        imag = new_imag;
    }
    Complex() {
        real = 0;
        imag = 0;
    }
    
    double getReal() const {
        return real;
    }
    
    double getimag() const {
        return real;
    }
    
    void setReal(double num) {
        real = num;
    }
    
    void setImag(double num) {
        imag = num;
    }
    
    Complex add(Complex num) {
        double newReal = real + num.real;
        double newImag = imag + num.imag;
        
        Complex result(newReal, newImag);
        return result;
    }
    Complex add(double num) {
        double newReal = real + num;
        double newImag = imag;
        
        Complex result(newReal, newImag);
        return result;
    }
    
    Complex subtract(Complex num) {
        double newReal = real - num.real;
        double newImag = imag - num.imag;
        
        Complex result(newReal, newImag);
        return result;
    }
    Complex subtract(double num) {
        double newReal = real - num;
        double newImag = imag;
        
        Complex result(newReal, newImag);
        return result;
    }
    
    Complex multiply(Complex num) {
        double newReal = real * num.real - imag * num.imag;
        double newImag = real * num.imag + imag * num.real;
        
        Complex result(newReal, newImag);
        return result;
    }
    Complex multiply(double num) {
        double newReal = real * num;
        double newImag = imag * num;
        
        Complex result(newReal, newImag);
        return result;
    }
    
    void show() const {
        if (imag)
            cout << real << (imag > 0 ? "+" : "") << imag << "i" << endl;
        else
            cout << real << endl; 
    }
    
    
};

int main(){
    double real, imag;
    cin>>real>>imag;
    Complex c1 = {real, imag};

    cin>>real>>imag;
    Complex c2 = {real, imag};

    double d1;
    cin>>d1;
    
    Complex result;
    //showing the numbers:
    cout<<"c1: "; c1.show();
    cout<<"c2: "; c2.show();
    cout<<"d1: "<<d1<<endl;

    // Check the opertions where both operands are complex
    result = c1.add(c2); 
    cout<<"c1+c2: "; result.show();
    
    
    result = c1.subtract(c2); 
    cout<<"c1-c2: "; result.show();
    
    result = c1.multiply(c2); 
    cout<<"c1*c2: "; result.show();
    
    // Check the opertions where one operator is complex, other is double

    result = c1.add(d1); 
    cout<<"c1+d1: "; result.show();
    
    
    result = c1.subtract(d1); 
    cout<<"c1-d1: "; result.show();
    
    result = c1.multiply(d1); 
    cout<<"c1*d1: "; result.show();
    
    return 0;
}