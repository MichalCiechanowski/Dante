#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int ilosc_cyfr_w_liczbie(int a);

int main(){
  char text[100]={0};
  int suma=0,T1[100]={0};
  long unsigned int a=0;
  printf("Podaj tekst:\n");
  scanf("%100[^\n]",text);
  for(long unsigned int i=0;i<strlen(text);i++){
    if((text[i]=='0')||(text[i]=='1')||(text[i]=='2')||(text[i]=='3')||(text[i]=='4')||(text[i]=='5')||(text[i]=='6')||(text[i]=='7')||(text[i]=='8')||(text[i]=='9')||(text[i]=='-')||(text[i]=='+')){

    }else{
      printf("Incorrect input");
      exit(1);
    }
  }
  a=0;
  int o=0,x=0;
  while(a<strlen(text)){
    x = atoi(&text[a]);
    T1[o]=x;
    suma+=T1[o];
    //printf("%d ",T1[o]);
    o++;
    if(a==0){
      a+=(ilosc_cyfr_w_liczbie(x));
    }else{
      a+=(1+ ilosc_cyfr_w_liczbie(x));
    }
  }
  printf("%d",suma);
  return 0;
}

int ilosc_cyfr_w_liczbie(int a){
  int wynik=1;
  while(abs(a)>10){
    a/=10;
    wynik++;
  }
  return wynik;
}