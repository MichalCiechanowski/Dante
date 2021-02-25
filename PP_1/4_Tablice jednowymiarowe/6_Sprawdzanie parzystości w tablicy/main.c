#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

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
    if(array[i]%2==0){
      printf("%d even\n",array[i]);
    } else printf("%d odd\n",array[i]);
  }
  return 0;
}