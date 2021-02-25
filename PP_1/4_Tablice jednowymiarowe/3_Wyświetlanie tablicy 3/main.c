#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int array[11];
  for(int i = 0;i < 11;i++){
    array[i]=i;
  }
  for(int i = 0;i < 11;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
  return 0;
}