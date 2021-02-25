#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "vector_utils.h"

int read_vector(int* vec, int size, int stop_value){
  int x=1,test,i;
  if(size<=0 || vec==NULL){
    return -1;
  }
  for(i=0;i<size;i++){
    test=scanf("%d",&x);
    if(x==stop_value){
      return i;
    }
    *(vec + i) = x;
    if(test==0){
      return -2;
    }
  }
  return i;
}
