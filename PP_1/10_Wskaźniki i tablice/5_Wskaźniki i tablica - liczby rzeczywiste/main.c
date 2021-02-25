#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t tt;
  float T[20];
  float *d = T;
  float *s = T;
  srand(time(&tt));
  for(int i=0;i<20;i++){
    *d = (double)rand()/RAND_MAX;
    printf("%.1f ",*d);
    d++;  
  }
  printf("\n");
  
  for(int i=0;i<10;i++){
    printf("%.1f ",*s);
    s+=2;
  }
  return 0;
}