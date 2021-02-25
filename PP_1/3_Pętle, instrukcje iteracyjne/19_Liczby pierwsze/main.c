#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int prime_test(int x);

int main(void){
    int x;
    for(;;){
        printf("Podaj liczbę całkowitą: ");
        int test = scanf("%d",&x);
        switch(test){
            case 0: printf("Incorrect input"); exit(1); break;
            case 1: 
                switch(prime_test(x)){
                    case 1: printf("YES\n");
                    break;
                    case 0: printf("NO\n");
                    break;
                }
            break;
    }
    return 0;
    }
}
int prime_test(int x){
    if(x<2) return 0;
    for(int i=x-1;i>1;i--){
        if(x%i==0) return 0;
    }
    return 1;
}