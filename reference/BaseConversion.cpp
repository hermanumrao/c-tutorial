//#include <conio.h>
//#include <ctype.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define CHAR_BIT 8
/// find max or min values without branching cpu
int minVal( int x, int y)
{
	int r;  // the result goes here /
	   //x= 1, x=2
    //int  r1 = (x < y); // true = 1
   // int  r11 = (x > y); // false = 0
    //int  r111 = (x << y); // 4


   


	int tmp = (x - y) & -(x < y);

	r = y + ((x - y) & -(x < y)); // min(x, y)
	return r;
}



int maxVal( int x, int y)
{
	int r;  // the result goes here 
	r = x - ((x - y) & -(x < y)); // max(x, y)
	return r;
}


bool DeterminingIntPowerOf2(unsigned int v) 
{ // we want to see if v is a power of 2
	bool f;         // the result goes here 

	f = (v & (v - 1)) == 0 ;

	return f;
}

//Compute modulus division by 1 << s without a division operator 
int remender(int n  ,  int d )
{	
	int r;
	r = n & (d - 1);	
	return r;
}

int trailing0s( int v)
{
	///int xorvalue = a ^ b; int xnor = !(a ^ b); cout << xorvalue << "\t" << xnor; // 15 0
	
	int c =0;
	if (v)
	{
	  v = (v ^ (v - 1)) >> 1; /*inverse 0 to 1 and vice versa   **/ // Set v's trailing 0s to 1s and zero rest
	  for (c = 0; v; c++)
	  {
		v >>= 1;
	  }
	}
	else
	{
	  c = CHAR_BIT * sizeof(v);
	}
	return c;
}

int signofinteger( int v)
{
	int sign;   // the result goes here 
	//sign = -(v < 0);  // if v < 0 then -1, else 0. 
	sign = v >> sizeof(int) * CHAR_BIT - 1;
	return sign;
}

int absVal( int v)
{
	unsigned int r;  // the result goes here 
	int const mask = v >> sizeof(int) * CHAR_BIT - 1;
	r = (v + mask) ^ mask;
	return v;
}

void decimal_to_anybase(int n, int base) 
{ 
  int i, m, digits[1000], flag=0; 
  i=0; 
   
  printf("\n\n[%d] converted to base [%d] : ", n, base); 
   
  while(n) 
  { 
     m=n%base; 
     digits[i]="0123456789abcdefghijklmnopqrstuvwxyz"[m]; 
     n=n/base; 
     i++; 
   } 
   //Eliminate any leading zeroes 
   for(i--;i>=0;i--) 
   { 
     if(!flag && digits[i]!='0')flag=1; 

     if(flag)printf("%c",digits[i]); 
   }    
} 


int main( int argc , char * argv[])
{
	int x = -8;
	unsigned int xx = x;

	absVal( -8);
	signofinteger(-8 );
	
	DeterminingIntPowerOf2(8);
	int div = remender( 77  ,   7 );
	
	trailing0s( 8);

	minVal( 4, 7);
	decimal_to_anybase(10, 2); 
	decimal_to_anybase(255, 16); 
	//getch(); 

	return 0;
}
