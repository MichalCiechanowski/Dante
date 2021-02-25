#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int day;
    printf("Podaj liczbę(1-7):");
    scanf("%d",&day);
    switch(day){
        case 1: printf("Poniedzialek");
        break;
        case 2: printf("Wtorek");
        break;
        case 3: printf("Sroda");
        break;
        case 4: printf("Czwartek");
        break;
        case 5: printf("Piatek");
        break;
        case 6: printf("Sobota");
        break;
        case 7: printf("Niedziela");
        break;
        default: printf("Incorrect input"); exit(1);
        break;
    }
    
    return 0;
}