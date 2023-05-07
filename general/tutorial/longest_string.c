#include<stdio.h>
#define MAXLINE 1000

int getline(char line[],int maxline);
void copy(char to[],char from[]);

int main ()
{
	int len ,max0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len = getline (line, MAXLINE)) > 0)
		if (len>max)
		{	max=len;
			copy(longest,line);
		}
	if(max>0)
		printf("%s",longest);
	return 0;
}

int getline( char s[], int lim)
{
	int c;
	for (int i=0; i,lim-
