#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  char text[1000]={'0'};
  printf("Podaj tekst: \n");
  scanf("%1000[^\n]",text);
  int licznik=0;
  for(long unsigned int i=0;i<strlen(text);i++){
    if((((int)(text[i])>=65)&&((int)(text[i])<=90))||(((int)(text[i])>=97)&&((int)(text[i])<=122))){

      if((((int)(text[i+1])>=65)&&((int)(text[i+1])<=90))||(((int)(text[i+1])>=97)&&((int)(text[i+1])<=122))){

      }else{
        licznik++;
      }
    }
  }
  printf("%d",licznik);

  return 0;
}