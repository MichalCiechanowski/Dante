#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "tested_declarations.h"
#include "rdebug.h"

#define VAL(p, i) (*((p) + (i)))

int czyfloat(char* tekst);
int validate(char* buf, int len);

enum type_t{
  INTEGER,
  DOUBLE,
  CHARACTER
};

struct data_t
{
  enum type_t type;
  union {
    int i;
    double d;
    char c;
  };
};

void display(struct data_t* data[], int size);
int read(struct data_t* data[], int* size);
int sort(struct data_t* data[], int size);

void malloc_dane(struct data_t* dane[100])
{
    for (int x = 99; x != -1; x--)
        VAL(dane, x) = malloc(sizeof(struct data_t));
}

void free_dane(struct data_t* dane[100])
{
    for (int x = 99; x != -1; x--)
        free(VAL(dane, x));
}

int main() {
    struct data_t* dane[100] = {0};
    malloc_dane(dane);

    int rozmiar = 0;

    if (read(dane, &rozmiar) == 1) {
        free_dane(dane);
        return 2;
    }

    sort(dane, rozmiar);

    display(dane, rozmiar);

    free_dane(dane);
    return 0;
}

int czyfloat(char* tekst) {
    int czy_byla = 0;
    while (*tekst != ' ' && *tekst != '\0')
    {
        if (*tekst == '.' && czy_byla == 1)
            return 1;
        if (isdigit(*tekst))
            czy_byla = 1;
        tekst++;
    }
    return 0;
}

int validate(char* buf, int len) {
    if (buf == NULL)
        return 1;
    if (len <= 0)
        return 1;

    for (int i = 1; i < len; i++) {
        if (VAL(buf, i) == '-' && VAL(buf, i + 1) == '.')
            return 1;
        if (VAL(buf, i) == '.' && isdigit(VAL(buf, i - 1)) && VAL(buf, i + 1) == ' ')
            return 1;
        if (VAL(buf, i) == '.' && isdigit(VAL(buf, i + 1)) && VAL(buf, i - 1) == ' ')
            return 1;
        if (isdigit(VAL(buf, i)) && VAL(buf, i + 1) == '-')
            return 1;
        if (isdigit(VAL(buf, i + 1)) && VAL(buf, i) == '-')
            continue;
        if (isdigit(VAL(buf, i + 1)) && VAL(buf, i) == '.')
            continue;
        if (VAL(buf, i + 1) == '.' && isdigit(VAL(buf, i)))
            continue;
        if (isdigit(VAL(buf, i + 1)) && isdigit(VAL(buf, i)))
            continue;
        if (isalpha(VAL(buf, i + 1)) && isalpha(VAL(buf, i)))
            return 1;
    }

    return 0;
}

void display(struct data_t* data[], int size) {
    if (size <= 0)
        return;
    if (data == NULL)
        return;

    for (int i = 0; i < size; i++) {
        if ((VAL(data, i))->type == CHARACTER)
            printf("%c", VAL(data, i)->i);
        else if ((VAL(data, i))->type == DOUBLE)
            printf("%lf", VAL(data, i)->d);
        else
            printf("%d", VAL(data, i)->i);
        if (i != size - 1)
            printf(" ");
    }
}

int read(struct data_t* data[], int* size) {
    if (size == NULL)
        return 1;
    if (data == NULL)
        return 1;
    char tekst[2001] = {0};
    printf("Enter elements (single characters, signed integers and doubles):\n");
    *tekst = ' ';
    fgets(tekst + 1, 2000, stdin);

    int len = strlen(tekst);
    if (*(tekst + len - 1) == '\n')
        *(tekst + len - 1) = '\0';

    if (validate(tekst, len) == 1) {
        printf("incorrect input data");
        return 1;
    }

    struct data_t dane;
    int x = 0;
    for (int i = 0; i < len; i++) {
        if (*(tekst + i) == ' ') {
            if (czyfloat(tekst + i + 1))
            {
                sscanf(tekst + i + 1, "%lf", &dane.d);
                dane.type = DOUBLE;
            }
            else if (sscanf(tekst + i + 1, "%d", &dane.i) == 1)
                dane.type = INTEGER;
            else if (sscanf(tekst + i + 1, "%c", &dane.c) == 1)
                dane.type = CHARACTER;
            **(data + x) = dane;
            x++;
            if (100 == x)
                break;
        }
    }

    if (size != NULL)
        *size = x;

    return 0;
}

int sort(struct data_t* data[], int size) {
    if (size <= 0)
        return 1;
    if (data == NULL)
        return 1;

    // bubble sort
    for (int i = 0; i < size - 1; i++)       
        for (int j = 0; j < size - i - 1; j++)
        {
            double pierwszy;
            if ((**(data + j)).type == CHARACTER)
                pierwszy = (double)(**(data + j)).c;
            else if ((**(data + j)).type == DOUBLE)
                pierwszy = (double)(**(data + j)).d;
            else
                pierwszy = (double)(**(data + j)).i;

            double drugi;
            if ((**(data + j + 1)).type == CHARACTER)
                drugi = (double)(**(data + j + 1)).c;
            else if ((**(data + j + 1)).type == DOUBLE)
                drugi = (double)(**(data + j + 1)).d;
            else
                drugi = (double)(**(data + j + 1)).i;

            int res = 0;
            if (pierwszy == drugi)
            {
                if ((**(data + j + 1)).type > (**(data + j)).type)
                    res = 1;
            }
            else if (pierwszy < drugi)
                res = 1;

            if (res) 
            {
                struct data_t tymczasowe = **(data + j + 1);
                **(data + j + 1) = **(data + j);
                **(data + j) = tymczasowe;
            }
    }

    return 0;
}

