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
    char field[50];
    char faculty[80];
    int year;
};

void show(const struct student_t* p);
struct student_t* read(struct student_t* p, int *err_code);
void display(const struct student_t* p);
void display_name(const struct student_t* student);
void display_surname(const struct student_t* student);
void display_index(const struct student_t* student);
void display_field(const struct student_t* student);
void display_faculty(const struct student_t* student);
void display_year(const struct student_t* student);
struct student_t* set(struct student_t* student, const char * name,
                      const char * surname, int index,
                      const char * field, const char * faculty,
                      int year, int *err_code);

int main() {
    int wynik;
    struct student_t p1, p2;
    set(&p2, "Michal", "Ciechanowski", 235844, "informatyka", "weeia", 2020, &wynik);
    read(&p1, &wynik);
    if (!wynik)
    {
        display(&p1);
        printf("\n");
        display(&p2);
        printf("\n");
        show(&p1);
    }
    else
    {
        printf("Incorrect input");
        printf("\n");
        display(&p2);
    }

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
    int ifield = 0;
    int ifaculty = 0;
    int isurname = 0;

    int koniec_name = 0;
    int koniec_surname = 0;
    int koniec_index = 0;
    int koniec_field = 0;
    int koniec_faculty = 0;
    int koniec_year = 0;

    int jest_numer_index = 1;
    int jest_numer_year = 1;
    int byl_rok = 0;

    printf("Podaj dane:");
    while (1) {
        znak = getchar();
        if ((ifaculty == 80) && znak != ',')
        {
            if (err_code) *err_code = 5;
            return NULL;
        }
        if ((ifield == 50) && znak != ',')
        {
            if (err_code) *err_code = 4;
            return NULL;
        }
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
                if (iname == 0) {
                    if (err_code) *err_code = 1;
                    return NULL;
                }
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
                if (isurname == 0) {
                    if (err_code) *err_code = 2;
                    return NULL;
                }
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
            if (jest_numer_index) {
                if (isdigit(znak))
                {
                    p->index = dodaj_cyfre(p->index, znak);
                }
                else
                {
                    jest_numer_index = 0;
                    if (znak == ',') koniec_index = 1;
                }
            }
        }
        else if (koniec_field == 0)
        {
            if (znak == ',') {
                if (ifield == 0) {
                    if (err_code) *err_code = 4;
                    return NULL;
                }
                koniec_field = 1;
                VAL(p->field, ifield) = 0;
            }
            else
            {
                VAL(p->field, ifield) = znak;
                ifield = ifield + 1;
            }
        }
        else if (koniec_faculty == 0)
        {
            if (znak == ',') {
                if (ifaculty == 0) {
                    if (err_code) *err_code = 5;
                    return NULL;
                }
                koniec_faculty = 1;
                VAL(p->faculty, ifaculty) = 0;
            }
            else
            {
                VAL(p->faculty, ifaculty) = znak;
                ifaculty = ifaculty + 1;
            }
        }
        else if (koniec_year == 0)
        {
            if (jest_numer_year) {
                if (isdigit(znak))
                {
                    p->year = dodaj_cyfre(p->year, znak);
                    byl_rok = 1;
                }
                else
                {
                    jest_numer_year = 0;
                    if (znak == '\n') koniec_year = 1;
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
    if (!koniec_field)
    {
        if (err_code) *err_code = 4;
        return NULL;
    }
    if (!koniec_faculty)
    {
        if (err_code) *err_code = 5;
        return NULL;
    }
    if (!koniec_year || !byl_rok)
    {
        if (err_code) *err_code = 6;
        return NULL;
    }


        
    if (err_code) *err_code = 0;
    return p;
}

void display(const struct student_t* p) {
    if (!p)
        return;
    printf("%s ", p->name);
    printf("%s, ", p->surname);
    printf("index number: %d, ", p->index);
    if (VAL(p->field, 0) == 'A' || VAL(p->field, 0) == 'E' || VAL(p->field, 0) == 'I' || VAL(p->field, 0) == 'O' || VAL(p->field, 0) == 'U' ||
        VAL(p->field, 0) == 'a' || VAL(p->field, 0) == 'e' || VAL(p->field, 0) == 'i' || VAL(p->field, 0) == 'o' || VAL(p->field, 0) == 'u')
        printf("was an ");
    else
        printf("was a ");
    printf("%s ", p->field);
    printf("student at the ");
    printf("%s ", p->faculty);
    printf("in ");
    printf("%d.", p->year);
}

void display_name(const struct student_t* student) {
    if (!student)
        return;
    printf("Student name: ");
    printf("%s", student->name);
}
void display_surname(const struct student_t* student) {
    if (!student)
        return;
    printf("Student surname: ");
    printf("%s", student->surname);
}
void display_index(const struct student_t* student) {
    if (!student)
        return;
    printf("Index: ");
    printf("%d", student->index);
}
void display_field(const struct student_t* student) {
    if (!student)
        return;
    printf("Field: ");
    printf("%s", student->field);
}
void display_faculty(const struct student_t* student) {
    if (!student)
        return;
    printf("Faculty: ");
    printf("%s", student->faculty);
}
void display_year(const struct student_t* student) {
    if (!student)
        return;
    printf("Year: ");
    printf("%d", student->year);
}

void show(const struct student_t* p) {
    display_name(p);
    printf("\n");
    display_surname(p);
    printf("\n");
    display_index(p);
    printf("\n");
    display_field(p);
    printf("\n");
    display_faculty(p);
    printf("\n");
    display_year(p);
}

struct student_t* set(struct student_t* student, const char* name,
    const char* surname, int index,
    const char* field, const char* faculty,
    int year, int* err_code) {
    if (!student || !name || !surname || !field || !faculty)
    {
        if (err_code) *err_code = 1;
        return NULL;
    }
    if (strlen(name) >= 20 || strlen(surname) >= 40 || strlen(field) >= 50 || strlen(faculty) >= 80)
    {
        if (err_code) *err_code = 1;
        return NULL;
    }
    strncpy(student->name, name, 20);
    strncpy(student->surname, surname, 40);
    student->index = index;
    strncpy(student->field, field, 50);
    strncpy(student->faculty, faculty, 80);
    student->year = year;

    if (err_code) *err_code = 0;
    return student;
}

int dodaj_cyfre(int numer, char cyfra) {
    numer *= 10;
    numer = numer + cyfra - '0';
    return numer;
}
