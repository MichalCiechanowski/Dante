#include <stdio.h>
#include "bit_set.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
  union bit_set num;
  printf("Podaj liczbe: ");
  if(scanf("%hhd", &num.x) != 1){
    printf("Incorrect input");
    return 1;
  }
  printf("%d %d %d %d %d %d %d %d", num.str.eight, num.str.seven, num.str.six, num.str.five, num.str.four, num.str.three, num.str.two, num.str.one);
  return 0;
}
