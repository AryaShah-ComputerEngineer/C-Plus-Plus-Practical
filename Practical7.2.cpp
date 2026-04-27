#include<iostream>
using namespace std;

class Complex {
    int real, imag;

public:
   
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(Complex c){
        return Complex(real -c.real,imag - c.imag);
    }
    

  
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
    
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, 5);
    Complex c4(5,10);
    Complex c5(2,5);

    Complex c3 = c1 + c2;
    Complex c6= c4 - c5;

    c3.display(); 
    c6.display(); 
    return 0;
}