/*this program prins series of fabonaaci
 * Date time 
 */
#include<iostream>
#include<time.h>
#include<stdint.h>

uint64_t fn(uint64_t a , uint64_t b)
{
	
	return b+a ;
}

int main()
{
	double start,end;
	uint64_t  a=1;
	uint64_t  b=1;
	std::cout<<("please input number of terms:" );
	int n; 
	std::cin>> n ;
	start=clock();
	while(n>1){
		uint64_t x=fn(a,b);
		n=n-1;
		if (b<0)
		{
			std::cout<<( n);
			n=0;
		}
		a=b;
		b=x;
		std::cout<<(b );
	}
	end=clock();
	std::cout<<("time:" );
	std::cout<<(end-start);
	return 0;
}
