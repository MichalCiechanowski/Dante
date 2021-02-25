#include <stdio.h>

int main(void)
{
    float a = 10;
    float b = 2;
    float c = a/b;

    printf("%f %f\n",a,b);
    printf("%f",a*b);
    printf("\n");
    printf("%.2f",c);
    printf("\n");
    printf("%f",a+b);
    printf("\n");
    printf("%f",a-b);
    printf("\n");


    //printf("fPI = %.3f\ndPI = %.3f\n",fPI,dPI);
    
    return 0;
}