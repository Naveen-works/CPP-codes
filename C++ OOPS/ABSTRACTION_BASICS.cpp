#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(float r, float i) : real(r), imag(i) {}

    // Overloading the + operator
    friend Complex operator + (const Complex &c) ;

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex operator + (const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

int main() {
    Complex c1(3.4, 5.6), c2(1.2, 3.8);
    Complex c3 = c1 + c2; // Calls overloaded + operator
    c3.display(); // Output: 4.6 + 9.4i

    return 0;
    
}
