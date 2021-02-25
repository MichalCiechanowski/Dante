#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    float r;
    for(;;){
        printf("Podaj promień koła:");
        scanf("%f",&r);
        if(r<=0){
            printf("incorrect input\n");
        }else{
            printf("Obwód koła: %.3f\n",2*M_PI*r);
            printf("Pole koła: %.3f",M_PI*r*r);
            break;
        }
    }
}
