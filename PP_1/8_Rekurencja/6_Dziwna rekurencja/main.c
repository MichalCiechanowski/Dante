#include <stdio.h>
#include <time.h>
//#include <math.h>
#include <stdlib.h>

long int fibonacci(int n);

int main(){
  int n;
  printf("Który wyraz ciagu chcesz wyznaczyć: ");
  if(scanf("%d",&n)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(n<0){
    printf("Incorrect input data");
    exit(2);
  }
  printf("%ld",fibonacci(n));
  return 0;
}

long int fibonacci(int n){
  if(n<0) return -1;
  if(n==0) return 1;
  if(n==1) return 2;
  return fibonacci(n-1)+fibonacci(n-2)+n;
}