#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){
  int A[4][4], B[4][4], C[4][4]={0};
  time_t tt;
  srand(time(&tt));
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      A[i][j] = rand();
      B[i][j] = rand();
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(i==j){
        C[i][j]=1;
      }
    }
  }

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",A[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",B[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",C[i][j]);
    }
    printf("\n");
  }
  return 0;
}