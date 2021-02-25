#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

#define VAL(p, i) (*((p) + (i)))

int dodaj_cyfre(int numer, char cyfra);

struct student_t {
    char name[20];
    char surname[40];
    int index;
};

struct student_t* read(struct student_t* p, int *err_code);
void show(const struct student_t* p);

int main() {
    int wynik;
    struct student_t p;

    read(&p, &wynik);
    if (!wynik)
        show(&p);
    else
        printf("Incorrect input");

    return wynik;
}

struct student_t* read(struct student_t* p, int* err_code) {
    if (!p) {
        if (err_code)
            *err_code = 1;
        return NULL;
    }
    memset(p, 0, sizeof(struct student_t));
    char poprzedni_znak = 0;
    char znak = 0;
    int iname = 0;
    int isurname = 0;
    int koniec_name = 0;
    int koniec_surname = 0;
    int koniec_index = 0;
    int jest_numer = 1;
    printf("Podaj dane:\n");
    while (1) {
        znak = getchar();
        if ((isurname == 40) && znak != ',')
        {
            if (err_code) *err_code = 2;
            return NULL;
        }
        if ((iname == 20) && znak != ',')
        {
            if (err_code) *err_code = 1;
            return NULL;
        }
        if (poprzedni_znak == ',' && znak == ' ')
        {
            poprzedni_znak = znak; continue;
        }
        if (koniec_name == 0)
        {
            if (znak == ',') {
                koniec_name = 1;
                VAL(p->name, iname) = 0;
            }
            else
            {
                VAL(p->name, iname) = znak;
                iname = iname + 1;
            }
        }
        else if (koniec_surname == 0)
        {
            if (znak == ',') {
                koniec_surname = 1;
                VAL(p->surname, isurname) = 0;
            }
            else
            {
                if (isdigit(znak))
                {
                    if (err_code)
                        *err_code = 2;
                    return NULL;
                }
                VAL(p->surname, isurname) = znak;
                isurname = isurname + 1;
            }
        }
        else if (koniec_index == 0)
        {
            if (jest_numer) {
                if (isdigit(znak))
                {
                    p->index = dodaj_cyfre(p->index, znak);
                }
                else
                {
                    jest_numer = 0;
                    if (znak == '\n') koniec_index = 1;
                }
            }
        }
        if (znak == '\n')
            break;
        poprzedni_znak = znak;
    }

    if (!koniec_name)
    {
        if (err_code) *err_code = 1;
        return NULL;
    }
    if (!koniec_surname)
    {
        if (err_code) *err_code = 2;
        return NULL;
    }
    if (!koniec_index)
    {
        if (err_code) *err_code = 3;
        return NULL;
    }

        
    if (err_code) *err_code = 0;
    return p;
}

void show(const struct student_t* p) {
    if (p) {
        printf("%s ", p->name);
        printf("%s, ", p->surname);
        printf("%d", p->index);
    }
}

int dodaj_cyfre(int numer, char cyfra) {
    numer *= 10;
    numer = numer + cyfra - '0';
    return numer;
}
