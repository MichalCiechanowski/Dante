#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float poly(float x);

int main(){
  float x;
  printf("Podaj x=");
  if(scanf("%f",&x)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Wynik %.2f",poly(x));
  
  return 0;
}

float poly(float x){
  return 5*x*x+12.55*x+0.75;
}