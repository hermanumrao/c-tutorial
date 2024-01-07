#include <iostream>
#include<bits/stdc++.h>

using namespace std;

/*  flags for 32 bit string 
skipws	=	01 //skipwhite space
left	=	02 //left justified in field
right	=	04 //right justified in field (default )
internal =	010 // left and right justified
dec		=	020 // use number base 10 for integers
oct		=	040 // use number base 8 for integers
hex		=	0100// use number base 16 for integers
showbase=	0200// show number base for integers
showpoint=	0400// print trailing zeros for floats
uppercase=01000// use 'E', 'x' instead of 'e', 'x'
showpos	=	02000// use '+' with positive integers
scientific=	04000// use scientific notation for floats
fixed	=	010000// use fixed point notation for floats
unitbuf = 	020000// flush after each output operation
stdio	=	040000 // flush after each character output
*/

int main(int argc, char const *argv[])
{
	ios_base::fmtflags oldf = cout.flags();					// saves format into a varible named oldf 
	cout<<cout.precision()<<endl;
	cout<<cout.fill()<<endl;
	cout<<cout.flags()<<endl;
	cout<<cin.flags()<<endl<<endl;
	cout.fill('#');cout.width(40);// sets # as filling charecter for blank space and 
	cout<<"hello world"<<endl;
	cout<<"hello world"<<endl;
	double pi = 3.141592653589793238462643383279502884;
	cout<<"pi="<<pi<<endl;
	cout.precision(15);
	cout<<"pi="<<pi<<endl;
	cout.precision(25);
	cout<<"pi="<<pi<<endl;
	cout<<"pi="<<pi<<endl;
	int n=234;
	cout.flags(ios::hex | ios::uppercase | ios::showbase);
	cout<<"n="<<n<<endl;
	cout.flags(ios::oct | ios::showbase);
	cout<<"n="<<n<<endl;
	cout.flags(oldf);		//restes format 
	cout<<"n="<<n<<endl;
	cout<<"pi="<<pi<<endl;
	ios_base::fmtflags oldf1=cout.setf(ios::hex | ios::uppercase);//saves format into a varible named oldf1
	cout.setf(oldf1);		//restes format 
	// int s,sum=0;
	// while(cin >>s)
	// 	sum+=s;
	// cout<<sum<<endl;
	// cin.clear();
	// while(cin >>s)
	// 	sum+=s;
	// cout<<sum<<endl;
	char buff[100];
	cin.get(buff,8);
	cout<<buff<<endl;
	cin.get(buff,'|');
	cout<<buff<<endl;
	return 0;
}