// I wrote this program to understand the working to argc and argv 
//it is used to take input directly from user in terminal/cmd line itself and also count the number of inputs

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std ;
int main(int argc, char* argv[])
{
	int sum=0;
	cout<<"number of arguments="<<argc<<endl;

	for(int i=1; i<argc;i++)
	{
		cout<<i<<"-->"<<argv[i]<<endl;
		sum+=atoi(argv[i]);
	}
	cout<<"sum="<<sum<<endl;
	return 0;
}


/* -->OUTPUT<--
arvind@arvind-ThinkBook-14-G2-ITL-Ub:~/Desktop/code$ g++ -g args.cpp
arvind@arvind-ThinkBook-14-G2-ITL-Ub:~/Desktop/code$ ./a.out 1 2 3 4
number of arguments=5
1-->1
2-->2
3-->3
4-->4
sum=10
arvind@arvind-ThinkBook-14-G2-ITL-Ub:~/Desktop/code$ ./a.out 1 2 3
number of arguments=4
1-->1
2-->2
3-->3
sum=6
arvind@arvind-ThinkBook-14-G2-ITL-Ub:~/Desktop/code$ ./a.out
number of arguments=1
sum=0
*/
