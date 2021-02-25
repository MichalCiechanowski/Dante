#include <stdio.h>
#include <time.h>
//#include <math.h>
#include <stdlib.h>

long long binary_exponentiation(long long a, unsigned int n);
int power_rec(int,int);

int main(){
  int x,n;
  printf("Podaj podstawe:");
  if(scanf("%d",&x)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Podaj wykladnik:");
  if(scanf("%d",&n)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("%lld",binary_exponentiation(x,n));
  return 0;
}

long long binary_exponentiation(long long a, unsigned int n){
  if(n==0){
    return 1;
  }
  if((n%2)==0){
    return binary_exponentiation(a,n/2)*binary_exponentiation(a,n/2);
  }
  return a*binary_exponentiation(a,n-1);
}