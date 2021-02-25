#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float T[100];
  float *a=T;
  float suma=0;
  int array_size;
  printf("Ile liczb chcesz wprowadzić?: ");
  if(scanf("%d",&array_size)==0){
    printf("Incorrect input");
    exit(1);
  }
  if((array_size>100)||(array_size<1)){
    printf("Incorrect input data");
    exit(2);
  }
  printf("Podaj liczby: ");
  for(int i=0;i<array_size;i++){
    if(scanf("%f",a)==0){
      printf("Incorrect input");
      exit(1);
    }
    a+=1;
  }
  for(int i=0;i<array_size;i++){
    a--;
    printf("%.2f ",*a);
    suma+=*a;
  }
  printf("\nSuma: %.2f\nSrednia: %.2f",suma,suma/array_size);
  return 0;
}