#include <stdio.h>
//demonstrates the difference between puts and printf

int main()
{	FILE *fp= fopen("sample.txt","r");
	if (!fp) {puts("file not found");       exit(0);}
	char a[30];
	int i=1;
	while (i<5) 
	{	//fscanf(fp,"%s",a);
		fgets(a,30,fp);
		puts(a);
		putc('|',stdout);
		printf("%s",a);
		i++;
	}
	fclose(fp);
}

