#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int array[100],size_of_array=0,test,x;
  printf("Podaj liczby: ");
  for(int i = 0;i < 100;i++){
    test = scanf("%d",&x);
    if(test==0){
      printf("Incorrect input");
      exit(1);
    }
    
    array[i] = x;
    size_of_array++;
    if(x==0) break;
  }
  for(int i = size_of_array;i >= 0;i--){
    if(i%2==0) printf("%d ",array[i]);
  }
  return 0;
}