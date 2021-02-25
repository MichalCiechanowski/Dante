#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    printf("Witaj w grze losowanie liczb !\n");
    time_t T;
    int seed = time(&T);
    srand(seed);
    int x = rand()%101,liczba;
    for(int i = 0;i<10;i++){
        printf("Zgadnij liczbę: ");
        scanf("%d",&liczba);
        if (liczba == x)
        {
            printf("wygrales");
            exit(0);
        }else if(liczba < x){
            printf("za malo\n");
        } else
        {
            printf("za duzo\n");
        }
    }
    printf("przegrales");
}
