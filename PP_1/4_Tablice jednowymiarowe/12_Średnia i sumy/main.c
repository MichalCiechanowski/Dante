#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    float array[1000],x,size_of_array=0,avg=0,avg_help=0,sum_of_bigger=0,sum_of_smaller=0,test;
    printf("Podaj liczby: ");
    for(int i = 0;i<1000;i++){
        test = scanf("%f",&x);
        if(test != 1) {
            printf("Incorrect input");    
            exit(1);
        }
        if(x==0){
            break;
        }else
        {
            array[i] = x;
            size_of_array++;
        }
    }
    if(size_of_array==0){
        printf("Brak danych");
        exit(0);
    }
    for(int i=0;i<size_of_array;i++){
        avg_help+=array[i];
    }
    avg=avg_help/size_of_array;
    //printf("%f",avg);
    for(int i = 0;i < size_of_array;i++){
        if(array[i]>avg){
            sum_of_bigger+=array[i];
        }else if(array[i]==avg){
            //nada   
        }else{
            sum_of_smaller+=array[i];
        }
    }
    printf("%.2f\n%.2f\n%.2f\n",avg,sum_of_bigger,sum_of_smaller);
    return 0;
}
