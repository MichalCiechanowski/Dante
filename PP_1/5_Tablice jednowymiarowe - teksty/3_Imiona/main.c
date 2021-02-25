#include <stdio.h>

int main(void) {
  printf("Podaj imię: \n");
  char name[100000];
  int p=0;
  scanf("%s",name);
  for(int i=0;i<29;i++){
    if(name[i]=='\0'){
      printf("Witaj %s!",name);
      p=1;
      break;
    }
  }
  if(p==0){
    printf("Witaj ");
    for(int i=0;i<30;i++){
      printf("%c",name[i]);
    }
    printf("!");  
  }
  
  return 0;
}