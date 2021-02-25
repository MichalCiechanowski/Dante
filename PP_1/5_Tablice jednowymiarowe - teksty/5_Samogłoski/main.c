#include <stdio.h>

int main() {
  char text[1001];
  int licznik=0,samogloski[12]={0};
  printf("Podaj tekst:\n");
  scanf("%1000[^\n]",text);
  for(int i=0;i<1001;i++){
    if(text[i]=='\0'){
      printf("Wynki: %d",licznik);
      break;
    }
    switch(text[i]){
      case 'A':
        if(samogloski[0]==0){
          samogloski[0]=1;
          licznik++;
        } 
        break;
      case 'a':
        if(samogloski[1]==0){
          samogloski[1]=1;
          licznik++;
        } 
        break;
      case 'E':
        if(samogloski[2]==0){
          samogloski[2]=1;
          licznik++;
        } 
        break;
      case 'e':
        if(samogloski[3]==0){
          samogloski[3]=1;
          licznik++;
        } 
        break;
      case 'O':
        if(samogloski[4]==0){
          samogloski[4]=1;
          licznik++;
        } 
        break;
      case 'o':
        if(samogloski[5]==0){
          samogloski[5]=1;
          licznik++;
        } 
        break;
      case 'U':
        if(samogloski[6]==0){
          samogloski[6]=1;
          licznik++;
        } 
        break;
      case 'u':
        if(samogloski[7]==0){
          samogloski[7]=1;
          licznik++;
        } 
        break;
      case 'Y':
        if(samogloski[8]==0){
          samogloski[8]=1;
          licznik++;
        } 
        break;
      case 'y':
        if(samogloski[9]==0){
          samogloski[9]=1;
          licznik++;
        } 
        break;
      case 'I':
        if(samogloski[10]==0){
          samogloski[10]=1;
          licznik++;
        } 
        break;
      case 'i':
        if(samogloski[11]==0){
          samogloski[11]=1;
          licznik++;
        } 
        break;
    }
  }
  return 0;
}