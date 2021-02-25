#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    printf("Podaj liczbę całkowitą: ");
    int x,c;
    int s = scanf("%d",&x);
    c = 1+(x>>31)-(-x>>31)+s*5;
    switch(c){
        case 5: printf("%d is negative", x);
            break;
        case 6: printf("%d is equal to 0", x);
            break;
        case 7: printf("%d is positive", x);
            break;
        case 0: printf("incorrect input");
            return 1;
            break;
        case 1: printf("incorrect input");
            return 1;
            break;
        case 2: printf("incorrect input");
            return 1;
            break;
    }
    //printf("%d",s);
    return 0;
}