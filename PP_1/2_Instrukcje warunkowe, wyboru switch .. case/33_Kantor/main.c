#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    float x;
    char q;
    printf("Podaj pierwszą liczbę:");
    int test = scanf("%f",&x);
    int k = x;
    k = k>>30;
    k += test*5;
    switch(k){
        case 0:
            printf("incorrect input");
            exit(1);
        case 5: 
            printf("Podaj symbol operacji:");
            scanf("%s",&q);
            switch(q){
                case 'f':
                    switch(q){
                    case 'f': x /= 4.7073;
                    break;
                    case 'd': x /= 3.5382;
                    break;
                    case 'e': x /= 4.2074;
                    break;
                    }
                break;
                case 'd':
                    switch(q){
                    case 'f': x /= 4.7073;
                    break;
                    case 'd': x /= 3.5382;
                    break;
                    case 'e': x /= 4.2074;
                    break;
                    }
                break;
                case 'e':
                    switch(q){
                    case 'f': x /= 4.7073;
                    break;
                    case 'd': x /= 3.5382;
                    break;
                    case 'e': x /= 4.2074;
                    break;
                    }
                break;
                default: 
                    printf("incorrect input");
                    exit(1);
                break;
            }
        break;
        case 4: 
            printf("incorrect input");
            exit(1);
        break;
    }
    printf("%.2f",x);
    return 0;
}