#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
  printf("podaj liczby: \n");
  int T1[10][10]={0},T2[2][2]={0},pom,licznik=0,Tpom1[81]={0},Tpom2[81]={0},a=0;
  for(int i=0;i<81;i++){
    Tpom1[i]=-1;
    Tpom2[i]=-1;
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(scanf("%d",&pom)==0){
        printf("incorrect input");
        exit(1);
      }
      T1[i][j]=pom;
    }
  }
  printf("podaj liczby: \n");
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      if(scanf("%d",&pom)==0){
        printf("incorrect input");
        exit(1);
      }
      T2[i][j]=pom;
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(T1[i][j]==T2[0][0]){
        if(((i+1)<=9)&&((j+1)<=9)){
          if(T1[i+1][j]==T2[1][0]){
            if(T1[i][j+1]==T2[0][1]){
              if(T1[i+1][j+1]==T2[1][1]){
                licznik++;
                Tpom2[a]=i;
                Tpom1[a]=j;
                a++;
              }
            }
          }
        }
      }
    }
  }
  printf("%d ",licznik);
  for(int i=0;i<81;i++){
    if((Tpom1[i]==Tpom2[i])&&(Tpom1[i]==-1)){
      
    }else{
      printf("\n%d %d",Tpom1[i],Tpom2[i]);
    }
  }
  return 0;
}