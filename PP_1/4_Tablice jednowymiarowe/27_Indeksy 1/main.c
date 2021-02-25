#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int x,size_of_array=0,array[100]={0},test;
    printf("Podaj liczby: ");
    for(int i = 0;i < 100;i++){
        test = scanf("%d",&x);
        if(test == 0){
            printf("Incorrect input");
            exit(1);
        }
        if(x!=0){
            array[i] = x;
            size_of_array++;
        }else{
            break;
        }
    }
    if(size_of_array<2){
      printf("not enough data available");
      exit(2);
    }
    /*for(int i = 0;i < size_of_array;i++){
        printf("%d ",array[i]);
    }*/
    //max_of_array
    int max = array[0],max_index;
    for(int i = 0;i < size_of_array;i++){
        if(max < array[i]){
            max = array[i];
            max_index = i;
        }
    }
    //min_of_array
    int min = array[0],min_index;
    for(int i = 0;i < size_of_array;i++){
        if(min > array[i]){
            min = array[i];
            min_index = i;  
        }
    }
    //avg_of_max_and_min_of_array
    int avg = (max_index+min_index)/2;
    //
    int sum_help = 0;
    for(int i = 0;i < size_of_array;i++){
      sum_help+=array[i];
    }
    if(sum_help/array[0]==size_of_array){
      printf("%d",array[0]);
    }else{
      printf("%d",array[avg]);
    }
    return 0;
}