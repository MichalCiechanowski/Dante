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
  int pom,S1=0,S2=0;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(scanf("%d",&pom)==0){
        printf("incorrect input");
        exit(1);
      }
      if((i+j)%2==0){
        S1+=pom;
      }else{
        S2+=pom;
      }
    }
  }
  printf("\n%d",S1-S2);
  
  return 0;
}