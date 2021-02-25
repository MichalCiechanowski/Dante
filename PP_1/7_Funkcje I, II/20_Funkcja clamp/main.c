#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int clamp(int x, int lo, int hi);

int main(){
  int x,lo,hi;
  printf("Podaj liczbę: ");
  if(scanf("%d",&x)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Podaj pierwszą granicę: ");
  if(scanf("%d",&lo)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Podaj drugą granicę: ");
  if(scanf("%d",&hi)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("%d",clamp(x,lo,hi));
  return 0;
}

int clamp(int x, int lo, int hi){
  if(lo>hi){
    int a,b;
    a=hi;
    b=lo;
    lo=a;
    hi=b;
  }
  if(x<=lo){
    return lo;
  }
  if(x>=hi){ 
    return hi;
  }
  if((x>=lo)&&(x<=hi)){
    return x;
  }
  return 1;
}