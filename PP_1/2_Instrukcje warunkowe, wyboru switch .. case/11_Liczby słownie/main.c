#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Podaj liczbę\n");
  int num;
  int test = scanf("%d",&num);

  if(test == 0){
    printf("Incorrect input");
    exit(1);
  } else if((num<0)||(num>10)){
    printf("Incorrect input data");
    exit(2);
  } else if(num == 0){
    printf("zero");
  } else if(num == 1){
    printf("jeden");
  } else if(num == 2){
    printf("dwa");
  } else if(num == 3){
    printf("trzy");
  } else if(num == 4){
    printf("cztery");
  } else if(num == 5){
    printf("piec");
  } else if(num == 6){
    printf("szesc");
  } else if(num == 7){
    printf("siedem");
  } else if(num == 8){
    printf("osiem");
  } else if(num == 9){
    printf("dziewiec");
  } else if(num == 10){
    printf("dziesiec");
  }
  return 0;
}