#include <stdio.h>

int main() {
  int T[10];
  int *d = T;
  for(int i=0;i<10;i++){
    *d = i;
    printf("%d ",*d);
    d++;  
  }
  return 0;
}
