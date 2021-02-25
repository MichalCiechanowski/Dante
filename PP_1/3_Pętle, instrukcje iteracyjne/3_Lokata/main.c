#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prime_test(int x);

int main(void){
    float kwota;
    int liczba_miesiecy,t1,t2;
    printf("Podaj kwotę:");
    t1 = scanf("%f",&kwota);
    if((t1!=1)||(kwota<0)){
        printf("Incorrect input");
        exit(1);
    }
    printf("Podaj liczbę miesięcy:");
    t2 = scanf("%d",&liczba_miesiecy);
    if((t2!=1)||(liczba_miesiecy<0)){
        printf("Incorrect input");
        exit(1);
    }
    for(int i=liczba_miesiecy;i>0;i--){
        kwota*=1.01;
    }
    printf("Kwota po lokoacie %.2f",kwota);
}
