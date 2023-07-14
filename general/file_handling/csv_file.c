#include <stdio.h>                                   
#include <stdlib.h>
#include <string.h>
// demonstrates the use of strtok();
// the csv file has the following written in it
// ketgk,b,twbt,etg,et
//tg,e,erbr,rgt
//qwgr,reg,reg,,,w
//grg,,,,,,,w
//,

//end

int main()    
{       FILE *fp= fopen("smple.csv","r");
	if (!fp) {puts("file not found");	exit(0);}
        char a[20];
//	char b[10];
        int i=1;    
        while (i<5)     
        {       //fscanf(fp,"%s",a);    
                fgets(a,30,fp); 
		int j=0;
		char *b=strtok(a,","); puts(b);
		while(j<3) { char *b=strtok(NULL,","); puts(b); j++;}
                //puts(a);    
                putc('|',stdout);    
//                printf("%s",a);    
                i++;    
        }    
        fclose(fp);    
} 
