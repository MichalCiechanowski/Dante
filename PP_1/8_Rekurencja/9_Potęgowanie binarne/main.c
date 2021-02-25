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
  if(n%2==1) return a*power_rec(a*a, (n-1)/2);
  return power_rec(a*a, (n)/2);
}


int power_rec(int a, int n){
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