#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int sign(int value);

int main(){
  int d;
  printf("Podaj liczbe: ");
  switch(scanf("%d",&d)){
    case 0:
      printf("Incorrect input ");
      exit(1);
      break;
  }
  switch(sign(d)){
    case 1:
      switch(d){
        case 0:
          printf("zero");
          break;
        default:
          printf("positive");
          break;
      }
      break;
    case -1:
      printf("negative");
      break;
  }
  return 0;
}

int sign(int value){
  int x = value<0?-1:1;
  return x;
}