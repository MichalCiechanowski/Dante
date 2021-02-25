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

void array_multiplier(int T1[4][4], int T2[4][4]){
  int T3[4][4]={0},s=0;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      s=0;
      for(int k=0;k<4;k++){
        s+=T1[i][k]*T2[k][j];
      }
      T3[i][j]=s;
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",T3[i][j]);
    }
    printf("\n");
  }
}

void array_rows_sum(int tab[4][4]){
  int T3[4]={0},s=0;
  for(int i=0;i<4;i++){
    s=0;
    for(int j=0;j<4;j++){
      s+=tab[i][j];
    }
    T3[i]=s;
  }
  for(int i=0;i<4;i++){
    printf("%d ",T3[i]);
  }
}
void array_columns_sum(int tab[4][4]){
  int T3[4]={0},s=0;
  for(int i=0;i<4;i++){
    s=0;
    for(int j=0;j<4;j++){
      s+=tab[j][i];
    }
    T3[i]=s;
  }
  for(int i=0;i<4;i++){
    printf("%d ",T3[i]);
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
  array_rows_sum(A);
  printf("\n");
  array_columns_sum(A);
  printf("\n");
  array_rows_sum(B);
  printf("\n");
  array_columns_sum(B);
  printf("\n");
  array_rows_sum(C);
  printf("\n");
  array_columns_sum(C);
  
  
  return 0;
}