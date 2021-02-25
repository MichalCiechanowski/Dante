#include <stdio.h>
#include <stdint.h>
#include "tested_declarations.h"
#include "rdebug.h"

void dec_to_bin(uint32_t n, int bin[32]);
uint32_t bin_to_dec(int bin[32]);
int toggle_bit(uint32_t* pvalue, int b);
int set_bit(uint32_t* pvalue, int b);
int clear_bit(uint32_t* pvalue, int b);
int isset_bit(const uint32_t* pvalue, int b);



int main(){
  uint32_t number;
  int index, operation_index;
  printf("Enter a value: \n");
  if (scanf("%u", &number) == 0) {
    printf("Incorrect Input");
    return 1;
  }
  printf("Enter an index of a bit:\n");
  if (scanf("%d", &index) == 0) {
    printf("Incorrect Input");
    return 1;
  }
  if (index < 0 || index > 31) {
    printf("Invalid bit index");
    return 2;
  }
  printf("Select operation (0-toggle, 1-set, 2-clear, 3-read):\n");
  if (scanf("%d", &operation_index) == 0) {
    printf("Incorrect Input");
    return 1;
  }

  switch(operation_index){
    case 0:
      toggle_bit(&number, index);
      printf("%X", number);
      break;
    case 1:
      set_bit(&number, index);
      printf("%X", number);
      break;
    case 2:
      clear_bit(&number, index);
      printf("%X", number);
      break;
    case 3:
      printf("%d", isset_bit(&number, index));
      break;
    default:
      printf("Invalid operation");
      return 2;
  }
  return 0;
}

uint32_t bin_to_dec(int bin[32]){
  uint32_t dec = 0; 
  int base = 1;
  for (int i = 0; i < 32; i++) {
    dec += *(bin + i) * base;
    base *= 2;
  }
  return dec;
}
void dec_to_bin(uint32_t n, int bin[32]){
  for (int i = 0; i < 32; i++)
    *(bin + i) = 0;
  int i = 0;
  while (n > 0) {
    *(bin + i) = n % 2;
    n = n/2;
    i++;
  }
}

int toggle_bit(uint32_t* pvalue, int b){
  if (pvalue == NULL || b < 0 || b > 31)
    return -1;
  int bin[32] = {0};
  dec_to_bin(*pvalue, bin);
  if (*(bin + b) == 1){
    *(bin + b) = 0;
  }else{
    *(bin + b) = 1;
  }
  *pvalue = bin_to_dec(bin);
  return 0;
}

int set_bit(uint32_t* pvalue, int b){
  if (pvalue == NULL || b > 31 || b < 0){
    return -1;
  }
  int bin[32] = {0};
  dec_to_bin(*pvalue, bin);
  *(bin + b) = 1;
  *pvalue = bin_to_dec(bin);
  return 0;
}

int clear_bit(uint32_t* pvalue, int b){
  if (pvalue == NULL || b > 31 || b < 0){
    return -1;
  }
  int bin[32] = {0};
  dec_to_bin(*pvalue, bin);
  *(bin + b) = 0;
  *pvalue = bin_to_dec(bin);
  return 0;
}

int isset_bit(const uint32_t* pvalue, int b){
  if (pvalue == NULL || b < 0 || b > 31)
    return -1;
  int bin[32] = {0};
  dec_to_bin(*pvalue, bin);
  if (*(bin + b) == 1){
    return 1;
  }else{
    return 0;
  }
}
