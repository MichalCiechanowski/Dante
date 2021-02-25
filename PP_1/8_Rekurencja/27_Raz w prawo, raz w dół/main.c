#include <stdio.h>
#include <time.h>
//#include <math.h>
#include <stdlib.h>

int is_destination_reachable(int sx, int sy, int dx, int dy);
int is_div(int x,int e);

int main(){
  int x1,x2,y1,y2;
  printf("Podaj współrzędne początkowe:");
  if(scanf("%d",&x1)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(scanf("%d",&y1)==0){
    printf("Incorrect input");
    exit(1);
  }
  printf("Podaj współrzędne końcowe:");
  if(scanf("%d",&x2)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(scanf("%d",&y2)==0){
    printf("Incorrect input");
    exit(1);
  }
  if(is_destination_reachable(x1,y1,x2,y2)){
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
}

int is_destination_reachable(int sx, int sy, int dx, int dy){
  if((sx==dx)&&(sy==dy)) return 1;

  if(sx>dx) return 0;
  if(sy>dy) return 0;

  return (is_destination_reachable(sx + sy, sy, dx, dy) || is_destination_reachable(sx, sy + sx, dx, dy)); 
}
