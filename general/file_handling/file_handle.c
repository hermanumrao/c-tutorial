#include<stdio.h>
#include<errno.h>
int main()
{	FILE *fpi=fopen("input.txt","r");
	FILE *fpo=fopen("output.txt","w");
	perror("fopen");
	printf("%d",errno);
	fflush(stdout);
	fclose(fpi);
	fclose(fpo);
}
