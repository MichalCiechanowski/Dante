#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 2;
    double c = a/b;

    printf("%d %d\n",a,b);
    printf("%d",a*b);
    printf("\n");
    printf("%.2f",c);
    printf("\n");
    printf("%d",a+b);
    printf("\n");
    printf("%d",a-b);
    printf("\n");


    //printf("fPI = %.3f\ndPI = %.3f\n",fPI,dPI);
    
    return 0;
}