//Michał Ciechanowski 235844
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int prime_test(int x){
  for(int i=2;i<=sqrt(x);i++){
    if(abs(x)%i==0) return 1;
  }
  if(x<2) return 2;
  return 0;
}

int main(void) {
  /*int num;
  printf("Podaj liczbę a ja powiem czy jest podzielna przez 2 lub 3: ");
  scanf("%d",&num);
  if(num%3==0){
    printf("Liczba %d jest podaielna przez 3\n",num);
  } else printf("Liczba %d nie jest podzielna przez 3\n",num);
  if(num%2==0){
    printf("Liczba %d jest podzielna przez 2\n",num);
  } else printf("Liczba %d nie jest podzielna przez 2\n",num);*/
  
  int array[26];
  for(int i=0;i<26;i++){
    array[i] = 65+i;
  }
  for(int i=0;i<26;i++){
    printf("%d %c %c\n",array[i],array[i],array[i]+32);
  }
  return 0;
}