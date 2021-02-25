#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int prime_test(int x){
  for(int i=2;i<=sqrt(x);i++){
    if(abs(x)%i==0) return 1;
  }
  if(x<2) return 2;
  return 0;
}

int main(void) { 
  int array[10],test;
  printf("Podaj 2 liczby: ");
  for(int i = 0;i < 10;i+=2){
    test = scanf("%d %d",&array[i],&array[i+1]);
    if(test == 0){
      printf("Input data type error");
      exit(1);
    }
  }
  
  if(test == 1){
    printf("Input data type error");
    exit(1);
  }
  
  for(int i = 0;i < 10;i++){
    if(prime_test(array[i])==1){
      printf("%d composite\n",array[i]);
    }
    if(prime_test(array[i])==0){
      printf("%d prime\n",array[i]);
    }
    if(prime_test(array[i])==2){
      printf("%d other\n",array[i]);
    }
  }
  return 0;
}