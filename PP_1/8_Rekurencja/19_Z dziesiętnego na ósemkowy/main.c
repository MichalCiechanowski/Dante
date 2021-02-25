#include <stdio.h>
#include <time.h>
//#include <math.h>
#include <stdlib.h>

unsigned long long decimal_to_octal(unsigned int number);

int main(){
  unsigned int x;
  printf("Podaj liczbe: ");
  if(scanf("%u",&x)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("%llu",decimal_to_octal(x));
  return 0;
}

unsigned long long decimal_to_octal(unsigned int number){
  if(number<8) return number;
  else{
    return (decimal_to_octal(number/8)*10)+(number%8);
  }
}