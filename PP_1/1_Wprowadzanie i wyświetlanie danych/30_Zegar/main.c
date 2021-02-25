#include <stdio.h>
#include <math.h>

int main(void)
{
    /*printf("Podaj liczby:\n");
    int a,b;
    scanf("%d %d",&a,&b);
    //printf("%d %d",a,b);*/

    //zegar
    printf("Podaj czas:");
    int a;
    scanf("%d",&a);
    int hh = floor(a/3600);
    int mm = floor((a - (3600*hh))/60);
    int ss = (a - hh*3600 - mm * 60);
    //printf("%d",hh);
    printf("%02d:%02d:%02d",hh,mm,ss);

    return 0;
}