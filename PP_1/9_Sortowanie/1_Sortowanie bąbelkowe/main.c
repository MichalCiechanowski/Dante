#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "vector_utils.h"

int main(){
  int size=150,tab[150]={0};
  for(int i=0;i<size;i++){
    tab[i]=1234567898;
  }
  printf("Podaj wektor:");
  int test = read_vector(tab, size, 0);
  if(test==-2){
    printf("Incorrect input");
    exit(1);
  }
  if(test==-1){
    printf("Not enough data available");
    exit(3);
  }
  bubble_sort(tab, size);
  return 0;
}