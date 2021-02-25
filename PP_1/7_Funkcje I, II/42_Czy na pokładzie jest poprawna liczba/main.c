#include <stdio.h>
#include <time.h>
#include <math.h>

int is_int(const char tab[]);
int is_float(const char tab[]);
int is_hexa(const char tab[]);

int array_len(const char tab[]);

int main(){
  char text[100];
  printf("Podaj tekst: ");
  scanf("%s",text);
  if(is_int(text)){
    printf("TAK\n");
  }else{
    printf("NIE\n");
  }
  if(is_float(text)){
    printf("TAK\n");
  }else{
    printf("NIE\n");
  }
  if(is_hexa(text)){
    printf("TAK\n");
  }else{
    printf("NIE\n");
  }
  return 0;
}

int is_int(const char tab[]){
  for(int i=0;i<array_len(tab);i++){
    if((tab[i]=='0')||(tab[i]=='1')||(tab[i]=='2')||(tab[i]=='3')||(tab[i]=='4')||(tab[i]=='5')||(tab[i]=='6')||(tab[i]=='7')||(tab[i]=='8')||(tab[i]=='9')||(tab[i]=='\0')||(tab[i]=='-')){

    }else{
      return 0;
    }
  }
  return 1;
}
int is_float(const char tab[]){
  int ilosc_przecinkow=0,ilosc_pl=0,ilosc_min=0,ilosc_e=0;
  for(int i=0;i<array_len(tab);i++){
    if((tab[i]=='0')||(tab[i]=='1')||(tab[i]=='2')||(tab[i]=='3')||(tab[i]=='4')||(tab[i]=='5')||(tab[i]=='6')||(tab[i]=='7')||(tab[i]=='8')||(tab[i]=='9')||(tab[i]=='\0')||(tab[i]=='.')||(tab[i]=='e')||(tab[i]=='E')||(tab[i]=='+')||(tab[i]=='-')){
      if(tab[i]=='.'){
        ilosc_przecinkow++;
      }
      if(tab[i]=='+'){
        ilosc_pl++;
      }
      if(tab[i]=='-'){
        ilosc_min++;
      }
      if(tab[i]=='e'){
        ilosc_e++;
      }
      if(tab[i]=='E'){
        ilosc_e++;
      }
    }else{
      return 0;
    }
  }
  if(ilosc_min>=2){
    return 0;
  }
  if(ilosc_pl>=2){
    return 0;
  }
  if(ilosc_przecinkow!=1){
    return 0;
  }
  if((ilosc_pl==ilosc_min)&&(ilosc_pl!=0)){
    return 0;
  }
  if(!(ilosc_e<=1)){
    return 0;
  }
  return 1;
}
int is_hexa(const char tab[]){
  for(int i=0;i<array_len(tab);i++){
    if((tab[i]=='0')||(tab[i]=='1')||(tab[i]=='2')||(tab[i]=='3')||(tab[i]=='4')||(tab[i]=='5')||(tab[i]=='6')||(tab[i]=='7')||(tab[i]=='8')||(tab[i]=='9')||(tab[i]=='\0')||(tab[i]=='\0')||(tab[i]=='A')||(tab[i]=='B')||(tab[i]=='C')||(tab[i]=='E')||(tab[i]=='F')||(tab[i]=='a')||(tab[i]=='b')||(tab[i]=='c')||(tab[i]=='e')||(tab[i]=='f')||(tab[i]=='d')||(tab[i]=='D')){

    }else{
      return 0;
    }
  }
  return 1;
}

int array_len(const char tab[]){
  int i=0;
  while(tab[i]!='\0'){
    i++;
  }
  return i;
}