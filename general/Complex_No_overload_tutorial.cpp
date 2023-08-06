#include<bits/stdc++.h>

using namespace std;

class Complex
{
	public:
		float real;
		float imag;
		Complex(float r=0, float i=0) : real(r),imag(i) {}

		//operator overloading + - *
		Complex operator + (Complex cmp)
		{	Complex temp;
			temp.real =real+cmp.real;
			temp.imag =imag+cmp.imag;
			return temp;
		}
		Complex operator - (Complex cmp)
		{	Complex temp;
			temp.real =real-cmp.real;
			temp.imag =imag-cmp.imag;
			return temp;
		}
		Complex operator * (Complex cmp)
		{	Complex temp;
			temp.real =real*cmp.real+imag*cmp.imag;
			temp.imag =real*cmp.imag+imag*cmp.real;
			return temp;
		}
		

		//overloading output operator <<
	private:
		friend ostream & operator << (ostream & ostr, const Complex &c1)
		//overloading ostream operator to print in a better way 
		{	return ostr << c1.real<<"+"<<c1.imag<<"i";
		}
		friend istream & operator >> (istream & istr, const Complex &c1)
		//overloading ostream operator to print in a better way 
		{	cout<<"real part:";
			istr>>c1.real;
			cout<<"\nimaginary part:";
			istr>>c1.imag;
			return istr;
		}
		friend int operator == (const Complex &c1 , const Complex &c2)		// for all relational operators use this syntax
		{	
			return (c1.real==c2.real && c1.imag==c2.imag);
		}
};

int main()
{
	float real,imag;
	cout << "enter value for real and imaginary parts for c1"<<endl;
	cin >> real;
	cin >> imag;
	Complex c1(real,imag);
	cout << "enter value for real and imaginary parts for c2"<<endl;
	cin >> real;
	cin >> imag;
	Complex c2(real,imag),res;
	res = c1+c2;
	cout<<res<<endl;
	cout<<(c1==c2);
}