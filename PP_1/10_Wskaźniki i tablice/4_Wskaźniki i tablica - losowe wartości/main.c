#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t tt;
  int T[20];
  int *d = T;
  int *s = T;
  srand(time(&tt));
  for(int i=0;i<20;i++){
    *d = rand();
    printf("%d ",*d);
    d++;  
  }
  printf("\n");
  
  for(int i=0;i<10;i++){
    printf("%d ",*s);
    s+=2;
  }
  return 0;
}