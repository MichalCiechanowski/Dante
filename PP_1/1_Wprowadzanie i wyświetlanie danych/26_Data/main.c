#include <stdio.h>
//#include<string.h>
#include <math.h>

int main(void)
{
    printf("Podaj datę: ");
    char date[10];
    scanf("%[^\n]",date);

    printf("Day:%10c%c\nMonth:%8c%c\nYear:%7c%c%c%c",date[0],date[1],date[3],date[4],date[6],date[7],date[8],date[9]);
    return 0;
}