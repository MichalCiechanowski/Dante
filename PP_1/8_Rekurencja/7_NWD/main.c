#include <stdio.h>
#include <time.h>
//#include <math.h>
#include <stdlib.h>

int GCD(int a, int b);

int main(){
  int a,b;
  printf("Podaj a: ");
  if(scanf("%d",&a)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Podaj b: ");
  if(scanf("%d",&b)==0){
    printf("Incorrect input");
    exit(1);
  }

  printf("%d",GCD(a,b));
  return 0;
}

int GCD(int a, int b){
  if(a<0) a=-a;
  if(b<0) b=-b;
  if(b==0) return a;
  return GCD(b,a%b);
}