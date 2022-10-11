//this program prins series of fabonaaci
#include<iostream>
#include<time.h>
#include<stdint.h>
// function to find next term of series
uint64_t fn(uint64_t a,uint64_t b,uint64_t n)
{
	uint64_t c=b+a;
	std::cout<< (b);
	if (b<0)
		{
			std::cout<< ("ending stack ");
			std::cout<< (n);
			n=0;
		}
	if (n>1){
		fn(b,c,n-1);
	}
	return c ;
}
int main()
{
	double start,end;
	uint64_t a=1;
	uint64_t b=1;
	std::cout<< ("please input number of terms:" );
	int n;
	std::cin>> (n) ;
	start=clock();
	fn(a,b,n);
	end=clock();
	std::cout<< ("time:" );
	std::cout<< (end-start);
	
	return 0;
}
