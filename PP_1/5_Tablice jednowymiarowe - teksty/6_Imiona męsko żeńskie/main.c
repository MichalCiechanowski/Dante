#include <stdlib.h>
#include <stdio.h>

int main(){
  char name[10]={'0'};
  printf("Podaj Imię: \n");
  scanf("%10[^\n]",name);
  for(int i=0;i<10;i++){
    if(name[9-i]!=0){
      if(name[9-i]==97){
        printf("Imie zenskie");
        exit(0);
      }else{
        printf("Imie meskie");
        exit(0);
      }
    }
  }
  
  return 0;
}