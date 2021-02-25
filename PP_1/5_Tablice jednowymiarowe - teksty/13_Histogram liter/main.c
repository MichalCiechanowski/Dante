#include <stdlib.h>
#include <stdio.h>

int main(){
  char text[1000]={0};
  printf("Podaj tekst: ");
  scanf("%1000[^\n]",text);
  int tab[26]={0};
  for(int i=0;i<=1000;i++){
    if(((int)(text[i])>=65)&&((int)(text[i])<=90)){
      tab[(int)(text[i])-65]++;
    }
    if(((int)(text[i])>=97)&&((int)(text[i])<=122)){
      tab[(int)(text[i])-97]++;
    }
  }
  for(int i=0;i<26;i++){
    printf("%c - %d\n",97+i,tab[i]);
  }
  return 0;
}