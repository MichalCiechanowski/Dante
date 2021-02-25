#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  char text[1000]={'0'};
  int klucz;
  printf("Podaj tekst: \n");
  scanf("%1000[^\n]",text);
  printf("Podaj znak kodowy:\n");
  scanf("%d",&klucz);
  for(long unsigned int i=0;i<strlen(text);i++){
    if(text[i]!=32){
      //skip space
      if(((int)(text[i])>=65)&&((int)(text[i])<=90)){
        if(((int)(text[i])+klucz)>90){
          text[i]+=(klucz-26);
        }else{
          text[i]+=klucz;
        }
      }
      if(((int)(text[i])>=97)&&((int)(text[i])<=122)){
        if(((int)(text[i])+klucz)>122){
          text[i]+=(klucz-26);
        }else{
          text[i]+=klucz;
        }
      }
    }
  }
  for(long unsigned int i=0;i<strlen(text);i++){
    printf("%c",text[i]);
  }
  return 0;
}