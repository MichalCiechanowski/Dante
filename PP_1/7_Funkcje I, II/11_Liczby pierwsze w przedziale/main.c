#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int is_prime(int a);

int main(){
  int x1,x2,o=0;
  printf("Podaj x1=");
  if(scanf("%d",&x1)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Podaj x2=");
  if(scanf("%d",&x2)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(x1>x2){
    printf("Incorrect input");
    exit(1);
  }
  while(x1!=x2+1){
    if(is_prime(x1)){
      printf("%d ",x1);
      o++;
    }
    x1++;
  }
  if(o==0){
    printf("Nothing to show");
  }
  //printf("%d",is_prime(1));
  return 0;
}

int is_prime(int a){
  if((a==1)||(a<=0)) return 0;
  for(int i=2;i<a;i++){
    if(a%i==0){
      return 0;
    }
  }
  return 1;
}