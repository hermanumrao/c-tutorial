// simple calc using switch case
// compile using gcc  switch_case.c -lm
#include<stdio.h>
#include <math.h>
int main()
{
    char ch;
    int a,b;
    scanf("%d %c %d",&a,&ch,&b);
    printf("%d\t%c\t%d\n\n",a,ch,b);

    switch(ch)
    {
        case '*':
            printf("%d",a*b);
            break;
        case '+':
            printf("%d",a+b);
            break;
        case '-':
            printf("%d",a-b);
            break;
        case '/':
            printf("%d",a/b);
            break;
        case '^':
            printf("%f",pow(a,b));
            break;
        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
    }
    return 0;
}
