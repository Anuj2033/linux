/*
Problem Statement: Implement a class Complex which represents the Complex Number data type. Implement the following:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers.

Code from Object Oriented Programming (SPPU - Second Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-se-comp-codes/OOP
*/

// BEGINNING OF CODE
#include <iostream>
using namespace std;

class Complex {
	private:
		float real; // Store real part of complex number
		float imag; // Store imaginary part of complex number
	public:
		Complex() {
		// default constructor
			real = 0.0;
			imag = 0.0;
		}
		Complex(float r, float i) {
		// parameterized constructor
			real = r;
			imag = i;
		}

		Complex operator+(Complex& obj) {
		// overloading + operator
			return Complex(real + obj.real, imag + obj.imag);
		}

		Complex operator*(Complex& obj) {
		// overloading * operator
			return Complex(real * obj.real, imag + obj.imag);
		}

		friend ostream& operator<<(ostream& os, Complex& obj) {
		// overloading << (output) operator
			os << obj.real << " + " << obj.imag << "i";
			return os;
		}

		friend istream& operator>>(istream& is, Complex& obj) {
		// overloading >> (input) operator
			is >> obj.real; // input real part
			is >> obj.imag; // input imaginary part
			return is;
		}
};

int main() {
	Complex c1, c2, result;
	// c1 stores value for first complex number
	// c2 stores value for second complex number
	// result stores addition/muliplication of the two

	cout<<endl<<"Enter first complex number (first real part then imaginary):\t";
	cin>>c1;
	cout<<"First complex number is:\t"<<c1<<endl;

	cout<<endl<<"Enter first complex number (first real part then imaginary):\t";
	cin>>c2;
	cout<<"Second complex number is:\t"<<c2<<endl;

	result = c1 + c2; // addition of c1 and c2
	cout<<endl<<"----------"<<endl<<"Addition is:\t"<<result;
	
	result = c1 * c2; // multiplication of c1 and c2
	cout<<endl<<"Multiplication is:\t"<<result<<endl<<"----------"<<endl;

	return 0;
}
// END OF CODE
