#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
  printf("podaj liczby: \n");
  int T1[5][5]={0},pom,suma1=0,suma2=0;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(scanf("%d",&pom)==0){
        printf("incorrect input");
        exit(1);
      }
      T1[i][j]=pom;
    }
  }
  
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(i==j){
        suma1+=T1[i][j];
      }
    }
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(i==j){
        suma2+=T1[i][4-j];
      }
    }
  }
  printf("%d %d",suma1,suma2);
  return 0;
}