#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    printf("Podaj 5 znaków:");
    char text[5];
    scanf("%[^\n]",text);
    int num=0;
    /*for(int i=0;i<5;i++){
        if(text[i]=='x') num++;
        if(text[i]=='y') num++;
        if(text[i]=='z') num++;
        if(text[i]=='2') num++;
        if(text[i]=='7') num++;
    }*/
    /*switch(text[0]){
        case 'x': num++;
        break;
        case 'y': num++;
        break;
        case 'z': num++;
        break;
        case '2': num++;
        break;
        case '7': num++;
        break;
    }
    switch(text[1]){
        case 'x': num++;
        break;
        case 'y': num++;
        break;
        case 'z': num++;
        break;
        case '2': num++;
        break;
        case '7': num++;
        break;
    }
    switch(text[2]){
        case 'x': num++;
        break;
        case 'y': num++;
        break;
        case 'z': num++;
        break;
        case '2': num++;
        break;
        case '7': num++;
        break;
    }
    switch(text[3]){
        case 'x': num++;
        break;
        case 'y': num++;
        break;
        case 'z': num++;
        break;
        case '2': num++;
        break;
        case '7': num++;
        break;
    }
    switch(text[4]){
        case 'x': num++;
        break;
        case 'y': num++;
        break;
        case 'z': num++;
        break;
        case '2': num++;
        break;
        case '7': num++;
        break;
    }*/
    if(text[0]=='x') num++;
    if(text[0]=='y') num++;
    if(text[0]=='z') num++;
    if(text[0]=='2') num++;
    if(text[0]=='7') num++;
        if(text[1]=='x') num++;
    if(text[1]=='y') num++;
    if(text[1]=='z') num++;
    if(text[1]=='2') num++;
    if(text[1]=='7') num++;
        if(text[3]=='x') num++;
    if(text[3]=='y') num++;
    if(text[3]=='z') num++;
    if(text[3]=='2') num++;
    if(text[3]=='7') num++;
        if(text[4]=='x') num++;
    if(text[4]=='y') num++;
    if(text[4]=='z') num++;
    if(text[4]=='2') num++;
    if(text[4]=='7') num++;
        if(text[2]=='x') num++;
    if(text[2]=='y') num++;
    if(text[2]=='z') num++;
    if(text[2]=='2') num++;
    if(text[2]=='7') num++;

    printf("Szukane znaki wystapily %d raz(y)",num);
    
    return 0;
}