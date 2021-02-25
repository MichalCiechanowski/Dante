#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int add(int a, int b);

int main(){
  int a,b;
  printf("Podaj pierwszą liczbę: ");
  switch(scanf("%d",&a)){
    case 0:
      printf("Incorrect input ");
      exit(1);
      break;
  }
  printf("Podaj drugą liczbę: ");
  switch(scanf("%d",&b)){
    case 0:
      printf("Incorrect input ");
      exit(1);
      break;
  }
  printf("Wynik: %d",add(a,b));
  
  return 0;
}

int add(int a, int b){
  return a+b;
} 