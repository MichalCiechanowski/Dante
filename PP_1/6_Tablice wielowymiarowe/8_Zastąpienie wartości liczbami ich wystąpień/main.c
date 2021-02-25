#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void print_array(int tab[15][15]){
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      printf("%d ",tab[i][j]);
    }
    printf("\n");
  }
}


int main(){
  printf("podaj liczby: \n");
  int T1[15][15]={0},pom,T2[30]={0};
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      if(scanf("%d",&pom)==0){
        printf("incorrect input");
        exit(1);
      }
      if((pom<0)||(pom>=30)){
        printf("value out of range");
        exit(2);
      }
      T1[i][j]=pom;
      T2[T1[i][j]]++;
    }
  }
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      T1[i][j]=T2[T1[i][j]];
    }
  }
  printf("\n");
  print_array(T1);
  return 0;
}