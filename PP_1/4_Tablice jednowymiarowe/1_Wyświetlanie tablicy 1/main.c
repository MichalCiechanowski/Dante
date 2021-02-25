#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int array[11] = {0,1,2,3,4,5,6,7,8,9,10};
    printf("%d %d %d %d %d %d %d %d %d %d %d\n",array[0],array[1],array[2],array[3],array[4],array[5],array[6],array[7],array[8],array[9],array[10]);
    for(int i=0;i<11;i++){
        printf("%d\n",array[i]);
    }
    return 0;
}
