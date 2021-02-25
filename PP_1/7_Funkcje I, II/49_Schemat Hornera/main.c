#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int horner(const char binary[]);

int main(){
  char bin[16]={0};
  printf("Wprowadz iczbe binarna: ");
  scanf("%16s",bin);
  if(strlen(bin)>16){
    printf("Incorrect input");
    exit(1);
  }
  for(long unsigned int i=0;i<strlen(bin);i++){
    if((bin[i]=='0')||(bin[i]=='1')||(bin[i]=='\0')){

    }else{
      printf("Incorrect input");
      exit(1);
    }
  }
  printf("%d",horner(bin));
  return 0;
}

int horner(const char binary[]){
  
  for(long unsigned int i=0;i<strlen(binary);i++){
    if((binary[i]=='0')||(binary[i]=='1')||(binary[i]=='\0')){

    }else{
      return -1;
    }
  }
  if(strlen(binary)==0){
    return -1;
  }
  int L=binary[0]-'0',c;
  for(long unsigned int i=1;i<strlen(binary);i++){
    c=binary[i]-'0';
    L=L*2+c;
  }
  return L;
}