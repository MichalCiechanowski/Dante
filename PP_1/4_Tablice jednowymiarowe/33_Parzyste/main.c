#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int array[10], test, even_num=0,help=0,help1=0,help2=0;
    printf("Podaj liczby:");
    for(int i = 0;i < 10;i++){
        test = scanf("%d",&array[i]);
        if(test != 1){
            printf("Incorrect input");
            exit(1);
        }
    }
    for(int i = 0;i < 10;i++){
        if(array[i]%2 == 0) even_num++;
    }
    if (even_num != 4){
        printf("Incorrect input data");
        exit(2);
    }
    for(int j = 0;j < 4;j++){
        for(int i = 0;i < 10;i++){
            if(array[i]%2==0){
                if((i%3!=0)||(i==0)){
                    help1 = array[i];
                    help2 = array[3*help];
                    array[i] = help2;
                    array[3*help] = help1;
                }
                help++;
            }
        }
        help = 0;
    }
    for(int i = 0;i < 10;i++){
        printf("%d ",array[i]);
    }
    return 0;
}