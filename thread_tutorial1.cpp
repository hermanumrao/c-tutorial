//compile using g++ -g name.cpp -l pthread
#include <iostream>
#include <cstdlib>
#include <thread>
using namespace std;

void fn1()
{
	while (true)
	{
		cout<<"fn1";
	}
}
void fn2()
{
	while (true)
	{
		cout<<"fn2";
	}
}



int main()
{
	thread t;
	t =thread{fn2};//creates new thread and thus the function runs in a core
    fn1();//this function will run in a different core since prev fn has already occupied the first one
	t.join();// compulsory to join to remove entries from regesters
}
