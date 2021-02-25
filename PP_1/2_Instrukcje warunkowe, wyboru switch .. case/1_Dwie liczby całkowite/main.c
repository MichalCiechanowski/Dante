#include <stdio.h>
#include <stdlib.h>

int main(void){
    int test1,test2,liczba1,liczba2;
    printf("Podaj dwie liczby: ");
    test1 = scanf("%d",&liczba1);
    if(test1==0){
        printf("Incorrect input");
        exit(1);
    }
    test2 = scanf("%d",&liczba2);
    if(test2==0){
        printf("Incorrect input");
        exit(1);
    }
    printf("%d",liczba1+liczba2);
    return 0;
}