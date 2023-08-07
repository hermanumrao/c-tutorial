#include<iostream>
#include<math.h>

using namespace std;

class Complex
{
	public:
		int real;
		int imag;
		Complex(int r=0, int i=0) : real(r),imag(i) {}

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
		Complex operator ++()//overloading the preincrement operator
		{
			real=real+1;
			return *this;
		}
		Complex operator ++( int )
		{
			Complex temp =*this;
			real+=1;
			return temp;
		}
		operator float()
		{
			return sqrt(real*real+imag*imag);
		}

	private:
			//overloading output operator <<
		friend ostream & operator << (ostream &, const Complex &);
		friend istream & operator >> (istream & , const Complex &);
		friend bool operator == (const Complex & , const Complex &);		// for all relational operators use this syntax
};

istream & operator >> (istream & istr, const Complex &c1)
		//overloading istream operator to take input in in a better way 
{	cout << "real part:";
	istr >> c1.real;
	cout << "\nimaginary part:";
	istr >> c1.imag;
	return istr;
} 

bool operator == (const Complex &c1 , const Complex &c2)		// for all relational operators use this syntax
{	
	return (c1.real==c2.real && c1.imag==c2.imag);
}

ostream & operator << (ostream & ostr, const Complex &c1)
	//overloading ostream operator to print in a better way 
{	return ostr << c1.real<<"+"<<c1.imag<<"i";
}

int main()
{
	int real,imag;
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
	cout<<++res<<endl;
	cout<<res<<endl;
	cout<<res++<<endl;
	cout<<res<<endl;
	cout<<(c1==c2);
	cout<<float(res);
}