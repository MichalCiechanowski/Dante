#include <stdio.h>
#include <time.h>
//#include <math.h>
#include <stdlib.h>

long power_rec(int a, int n);

int main(){
  int a,n;
  printf("Podaj a: ");
  if(scanf("%d",&a)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Podaj n: ");
  if(scanf("%d",&n)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(n<0){
    printf("Incorrect input data");
    exit(2);
  }
  printf("%ld",power_rec(a,n));
  
  return 0;
}

long power_rec(int a, int n){
  if(n<0){
    return 0;
  }
  if(n==0){
    return 1;
  }
  if(n<1){
    return a;
  }else{
    return a*power_rec(a,n-1);
  }
}