#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
  printf("podaj liczby: \n");
  int T1[5][5]={0},pom,max=-100000;
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
      if(T1[i][j]>max){
        max=T1[i][j];
      }
    }
    printf("%d ",max);
    max=-100000;
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      if(T1[j][i]>max){
        max=T1[j][i];
      }
    }
    printf("%d ",max);
    max=-100000;
  }

  return 0;
}