#include <stdio.h>
#include <time.h>
//#include <math.h>
#include <stdlib.h>

unsigned long sum_rec(int n);

int main(){
  int n;
  printf("Podaj liczbę, dla której chcesz policzyć sumę: ");
  if(scanf("%d",&n)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(n<=0){
    printf("Incorrect input data");
    exit(2);
  }
  printf("Wynik: %ld",sum_rec(n));
  return 0;
}

unsigned long sum_rec(int n){
  if(n<0) return 0;
  if(n==1) return 1;
  return sum_rec(n-1)+n;
}