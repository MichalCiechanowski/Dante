#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prime_test(int x);

int main(void){
    float liczba_pobrana, wynik = 0, test;
    printf("Podasj 10 liczb rzeczywistych a ja policzę ich sumę\n");
    for(int i=0;i<10;i++){
        printf("Podaj liczbę: ");
        test = scanf("%f",&liczba_pobrana);
        if(test != 1){
            printf("Incorrect input");
            exit(1);
        }
        wynik+=liczba_pobrana;
    }
    printf("\nSuma podanych liczb to: %f",wynik);
}
