#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(void) {
  double array[10],test;
  printf("Podaj 2 liczby: ");
  for(int i = 0;i < 10;i+=2){
    test = scanf("%lf %lf",&array[i],&array[i+1]);
    if((test == 0)||(array[i]==round(array[i])||(array[i+1]==round(array[i+1])))){
      printf("Input data type error");
      exit(1);
    }
  }
  
  if(test == 1){
    printf("Input data type error");
    exit(1);
  }
  
  for(int i = 0;i < 10;i++){
    printf("%d %lf\n",i,array[i]);
  }
  return 0;
}