#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct date_t {
    int day;
    int month;
    int year;
};

int validate(const struct date_t* d) {
    if (!d)
        return -1;
    if (d->day <= 0 || d->month <= 0 || d->month > 12)
        return 0;
    if (d->month == 2 && d->day == 29) {
        if (!((d->year % 4 == 0 && d->year % 100 != 0) || (d->year % 400 == 0)))
            return 0;
    }
    if (d->year % 4 != 0 && d->month == 2 && d->day == 29)
        return 0;
    if (d->month == 1 || d->month == 3 || d->month == 5 || d->month == 7 ||
        d->month == 8 || d->month == 10 || d->month == 12) {
        if (d->day > 31)
            return 0;
    }
    else
        if (d->day > 30)
            return 0;
    return 1;
}

struct date_t* set_date(struct date_t* d, int day, int month, int year, int* err_code) {
    if (!d) {
        if (err_code) *err_code = 1;
        return NULL;
    }

    d->day = day;
    d->month = month;
    d->year = year;
    
    if (err_code) *err_code = 0;

    return d;
}

void show(const struct date_t* d) {
    if (!d)
        return;
    printf("%02d-%02d-%04d", d->day, d->month, d->year);
}

struct date_t* read(struct date_t* d, int* err_code) {
    if (!d) {
        if (err_code) *err_code = 1;
        return NULL;
    }
    printf("Enter a date (formatted as dd-mm-yyyy): ");

    int day;
    int month;
    int year;
    if (scanf("%d-%d-%d", &day, &month, &year) != 3) {
        if (err_code) *err_code = 2;
        return NULL;
    }

    d->day = day;
    d->month = month;
    d->year = year;

    if (err_code) *err_code = 0;
    return d;
}

int main() {
    struct date_t d;
    int err = 0;
    set_date(&d, 0, 0, 0, &err);
    read(&d, &err);
    if (err == 2) {
        printf("Incorrect input");
        return 1;
    }
    if (validate(&d) == 1) {
        printf("Given date: ");
        show(&d);
        printf("\n");
        printf("Correct");
    }
    else
        printf("Incorrect");
}
