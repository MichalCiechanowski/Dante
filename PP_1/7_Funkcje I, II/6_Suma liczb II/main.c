#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float add(float a, float b);

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
  printf("Wynik: %f",add(a,b));
  
  return 0;
}

float add(float a, float b){
  return a+b;
} 