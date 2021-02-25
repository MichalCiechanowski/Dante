#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

unsigned long factorial_rec(int n);

int main(){
  int n;
  printf("Podaj n: ");
  if(scanf("%d",&n)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(!((n>=0)&&(n<=20))){
    printf("Incorrect input data");
    exit(2);
  }
  printf("%lu",factorial_rec(n));
  return 0;
}

unsigned long factorial_rec(int n){
  if(n<0){
    return 0;
  }
  if(n<2){
    return 1;
  }else{
    return n*factorial_rec(n-1);
  }
}