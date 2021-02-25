#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float toRadian(float a);
float toDegree(float a);

int main(){
  printf("Wybierz rodzaj konwersji (1=stopnie na radiany, 2=radiany na stopnie): ");
  int e;
  float x;
  if(scanf("%d",&e)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(e!=1){
    if(e!=2){
      printf("Incorrect input");
      exit(1);
    }
  }
  printf("Podaj miare kata: ");
  if(scanf("%f",&x)==0){
    printf("Incorrect input");
    exit(1);
  }
  switch(e){
    case 1:
      printf("Podaj miare kata: %.2f",toRadian(x));
      break;
    case 2:
      printf("Podaj miare kata: %.2f",toDegree(x));
      break;
  }
  return 0;
}

float toRadian(float a){
  float pi =  3.14159;
  return (a*pi)/180;
}
float toDegree(float a){
  float pi =  3.14159;
  return (a*180)/pi;
}