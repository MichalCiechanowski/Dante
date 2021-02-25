#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
  char text[1000];
  printf("Podaj tekst: \n");
  scanf("%1000[^\n]",text);
  int words_len[500] = {0}, word_temp_len=0;
  for(long unsigned int i=0;i<=strlen(text);i++){
    
      if((text[i]==32)||(text[i]=='\0')||(text[i]=='.')||(text[i]==',')||(text[i]=='-')||(text[i]=='\'')||(text[i]=='\"')){
        words_len[word_temp_len]++;
        word_temp_len=0;
      }else{
        word_temp_len++;
      }
    
  }
  for(long unsigned int i=1;i<500;i++){
    if(words_len[i]!=0){
      printf("%lu - %d\n",i,words_len[i]);
    }
  }
  return 0;
}