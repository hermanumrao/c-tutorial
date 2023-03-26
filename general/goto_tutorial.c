
#include<stdio.h>
int main()
{
    for (int i=0;i<5;i++)
    {
        printf("%d\n",i);
        if (i==2) goto label1;
    }

label1:
    printf("out");
    for (int i=0;i<5;i++)
    {
        printf("%d\n",i);
        if (i==8) goto label2;
    }

label2:
    printf("out");
    return 0;
}
