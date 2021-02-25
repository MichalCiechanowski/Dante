#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "vector_utils.h"

int bubble_sort(int tab[], int size){
  int is_sorted=0;
  if(size<=0) return 1;
  for(int i=0;i<size-1;i++){
    if(is_sorted==1) return 0;
    is_sorted=1;
    for(int j=0;j<size-i-1;j++){
      if(tab[j]>tab[j+1]){
        swap(&tab[j],&tab[j+1]);
        is_sorted=0;
      }
    }
    display_vector(tab,size);
  }
  return 0;
}

//

void quick_sort(int tab[],int lewy_index,int prawy_index){
  int v=tab[(lewy_index+prawy_index)/2],i,j;
  i=lewy_index;
  j=prawy_index;
  do{
    while(tab[i]<v) i++;
    while(tab[j]>v) j--;
    if(i<=j){
      swap(&tab[i],&tab[j]);
      i++;j--;
    }
  }
  while(i<=j);
  if(j>lewy_index) quick_sort(tab,lewy_index, j);
  if(i<prawy_index) quick_sort(tab, i, prawy_index);
}

int read_vector(int vec[], int size, int stop_value){
  int x=1,test,i;
  if(size<=0){
    return -1;
  }
  for(i=0;i<size;i++){
    test=scanf("%d",&x);
    if((x==0)&&(i==0)){
      return -1;
    }
    if(x==stop_value){
      return i;
    }
    vec[i]=x;
    if(test==0){
      return -2;
    }
    
  }
  return i;
}

void swap(int *a, int *b){
  int temp=*b;
  *b=*a;
  *a=temp;
}

void display_vector(const int vec[], int size){
  if(size<=0) return;
  for(int i=0;i<size;i++){
    if(!(vec[i]==1234567898))printf("%d ",vec[i]);
  }
  printf("\n");
}