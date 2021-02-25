#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct complex_t {
    float re;
    float im;
};

struct complex_t* set(struct complex_t* cp, float re, float im, int* err_code) {
    if (cp == NULL) {
        if (err_code) *err_code = 1;
        return NULL;
    }
    
    cp->re = re;
    cp->im = im;

    if (err_code) *err_code = 0;
    return cp;
}

void show(const struct complex_t* cp) {
    if (cp == NULL)
        return;
    if (cp->im < 0) {
        float im = -cp->im;
        printf("%.2f - i%.2f", cp->re, im);
    }
    else
        printf("%.2f + i%.2f", cp->re, cp->im);
}

float complex_abs(struct complex_t* cp, int * err_code) {
    if (cp == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return -1;
    }
    
    float result = sqrtf((float)(cp->re * cp->re + cp->im * cp->im));
    
    if (err_code != NULL)
        *err_code = 0;

    return result;
}

int read(struct complex_t* cp) {
    printf("Enter a complex number: ");
    if (scanf("%f", &cp->re) != 1) {
        printf("Incorrect input");
        return 1;
    }
    char c, i;
    if (scanf("%c", &c) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (scanf("%c", &i) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (scanf("%f", &cp->im) != 1) {
        printf("Incorrect input");
        return 1;
    }
    if (!(c == '-' || c == '+')) {
        printf("Incorrect input");
        return 1;
    }
    if (i != 'i') {
        printf("Incorrect input");
        return 1;
    }
    if (cp->im < 0) {
        printf("Incorrect input");
        return 1;
    }


    if (c == '-')
        cp->im *= -1;

    return 0;
}

int main() {
    struct complex_t cp1, cp2;

    int err_code;
    set(&cp1, 0, 0, &err_code);
    set(&cp2, 0, 0, &err_code);

    if (read(&cp1))
        return 1;
    if (read(&cp2))
        return 1;
    float l1 = complex_abs(&cp1, &err_code);
    float l2 = complex_abs(&cp2, &err_code);

    show(&cp1);
    printf("\n");
    show(&cp2);
    printf("\n");

    if (l1 > l2)
        printf("FIRST");
    else if (l1 < l2)
        printf("SECOND");
    else
        printf("EQUAL");

    return 0;
}

