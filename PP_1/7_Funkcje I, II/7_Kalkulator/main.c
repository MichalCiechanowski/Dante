#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "tested_declarations.h"
#include "rdebug.h"

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);

int main(){
  float a,b;
  printf("Podaj pierwszą liczbę: ");
  switch(scanf("%f",&a)){
    case 0:
      printf("Incorrect input ");
      exit(1);
      break;
  }
  printf("Podaj drugą liczbę: ");
  switch(scanf("%f",&b)){
    case 0:
      printf("Incorrect input ");
      exit(1);
      break;
  }
  printf("Suma: %f\n",add(a,b));
  printf("Roznica: %f\n",subtract(a,b));
  printf("Iloczyn: %f\n",multiply(a,b));
  if(b==0){
    printf("operation not permitted\n");
  }else{
    printf("Iloraz: %f\n",divide(a,b));
  }
  
  return 0;
}

float add(float a, float b){
  return a+b;
}
float subtract(float a, float b){
  return a-b;
} 
float multiply(float a, float b){
  return a*b;
} 
float divide(float a, float b){
  if(b!=0){
    return a/b;
  }else{
    return -1;
  }
} 