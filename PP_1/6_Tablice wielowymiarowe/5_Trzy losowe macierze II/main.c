#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void print_array(int tab[4][4]){
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",tab[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int A[4][4], B[4][4], C[4][4]={0};
  time_t tt;
  srand(time(&tt));
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      A[i][j] = rand()%100;
      B[i][j] = rand()%100;
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(i==j){
        C[i][j]=1;
      }
    }
  }
  print_array(A);
  printf("\n");
  print_array(B);
  printf("\n");
  print_array(C);
  printf("\n");
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",A[i][j]+B[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",A[i][j]-B[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",A[i][j]+B[i][j]+C[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",A[i][j]-B[i][j]-C[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",B[i][j]*-1);
    }
    printf("\n");
  }
  return 0;
}