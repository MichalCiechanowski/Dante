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
    int max = array[0],max_count = 0,max_help = 0;
    for(int i = 0;i < size_of_array;i++){
        if(max < array[i]){
            max = array[i];
        }
    }
    //
    for(int i = 0;i < size_of_array;i++){
      if(array[i]==max){
        max_help++;
        max_count +=i;
      } 
    }
    //min_of_array
    int min = array[0],min_count = 0,min_help = 0;
    for(int i = 0;i < size_of_array;i++){
        if(min > array[i]){
            min = array[i];
        }
    }
    //
    for(int i = 0;i < size_of_array;i++){
      if(array[i]==min){
        min_help++;
        min_count +=i;
      } 
    }
    //avg_of_max_and_min_of_array
    int avg = (max_count+min_count)/(max_help+min_help);
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
    //printf("%d %d %d %d\n%d",max_count,max_help,min_count,min_help,avg);
    return 0;
}