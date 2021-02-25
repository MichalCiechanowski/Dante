#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Podaj 9 cyfr:");
    int a,aa,bb,cc;
    scanf("%d",&a);
    aa = floor(a/1000000);
    bb = floor((a - aa*1000000)/1000);
    cc = floor(a-aa*1000000-bb*1000);
    printf("%03d\n%03d\n%03d\n",aa,bb,cc);
    return 0;
}