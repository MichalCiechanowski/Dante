#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float circumference(float b);

int main(){
  float d;
  printf("Podaj srednice kola: ");
  if((scanf("%f",&d)==0)||(circumference(d)<=0)){
    printf("Incorrect input ");
    exit(1);
  }
  printf("%.4f",circumference(d));
  return 0;
}

float circumference(float b){
  if(b<0){
    return -1;
  }
  return b*3.141592653589793238;
}