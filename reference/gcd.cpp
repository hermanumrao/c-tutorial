
#include <iostream>
#include <math.h>
using namespace std;

int gcd( int big, int small);

void comananfactor( int big, int small);

int main() {
	int num1, num2;
	cin >> num1 >> num2 ;										// Reading input from STDIN
	//cout << "Input number is " << num2 << " & "  << num2<< endl;		// Writing output to STDOUT

    if(  (num1 >= 1 &&   num1 <= pow( 10,12 ))  && (num2 >= 1 &&   num2 <= pow( 10,12 ))  )
    {
    if( num1 > num2 )
    comananfactor( num1, num2 );
    else
    comananfactor(num2, num1 );
    }
}

int gcd( int big, int small)
{  
     int rem = big%small;
    if( !rem) return small;
    
     
     gcd(  small , rem   );
}

void comananfactor( int big, int small)
{
    int igcd= gcd(big, small);
    
    int count = 0;
    for ( int i =1;  i<= sqrt(igcd) ; ++i)
    
    {
        if (igcd%i==0)
        {
        if (igcd/i == i)
                count += 1;
            else
                count += 2;
        }
        
    }
    cout << count << endl;
}




