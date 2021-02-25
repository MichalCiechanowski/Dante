#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void dec_to_bin(uint32_t n, int *bin)
{
  for (int i = 0; i < 32; i++)
    *(bin + i) = 0;
  int i = 0;
  while (n > 0) {
    *(bin + i) = n % 2;
    n /= 2;
    i++;
  }
}

int main(){
  uint32_t x;
  int* bin = malloc(32 * sizeof(int));
  int one_count=0;
  printf("Podaj wartość: ");
  if(scanf("%u",&x)!=1){
    printf("Incorrect input");
    free(bin);
    return 1;
  }

  dec_to_bin(x,bin);
  
  for(int i=0;i<32;i++){
    if(*(bin+i)==1){
      one_count++;
    }
  }
  if(one_count%2==0){
    printf("YES");
    free(bin);
    return 0;
  }
 
  printf("NO");
  free(bin);

  return 0;
}