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

void show(const struct complex_t* cp) {
    if (cp == NULL)
        return;
    if (cp->im < 0) {
        float im = -cp->im;
        printf("%.6f - i%.6f", cp->re, im);
    }
    else
        printf("%.6f + i%.6f", cp->re, cp->im);
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

int add(const struct complex_t* first, const struct complex_t* second, struct complex_t* result) {
    if (first == NULL || second == NULL || result == NULL)
        return 1;
    result->re = first->re + second->re;
    result->im = first->im + second->im;
    return 0;
}
        
int subtract(const struct complex_t* first, const struct complex_t* second, struct complex_t* result) {
    if (first == NULL || second == NULL || result == NULL)
        return 1;
    result->re = first->re - second->re;
    result->im = first->im - second->im;
    return 0;
}
             
int multiply(const struct complex_t* first, const struct complex_t* second, struct complex_t* result) {
    if (first == NULL || second == NULL || result == NULL)
        return 1;

    float a = first->re;
    float b = first->im;
    float c = second->re;
    float d = second->im;

    result->re = a * c - b * d;
    result->im = a * d + b * c;
    return 0;
}
             
int divide(const struct complex_t* first, const struct complex_t* second, struct complex_t* result) {
    if (first == NULL || second == NULL || result == NULL)
        return 1;
    if (second->re == 0.0f && second->im == 0.0f)
        return 2;

    float a = first->re;
    float b = first->im;
    float c = second->re;
    float d = second->im;

    // Computing c * c + d * d will overflow even in cases where the actual result of the division does not overflow.
    if (fabsf(d) <fabsf(c))
    {
        float doc = d / c;
        result->re = (a + b * doc) / (c + d * doc);
        result->im = (b - a * doc) / (c + d * doc);
    }
    else
    {
        float cod = c / d;
        result->re = (b + a * cod) / (d + c * cod);
        result->im = (-a + b * cod) / (d + c * cod);
    }

    return 0;
}

int main() {
    struct complex_t cp1, cp2;

    int err_code;
    set(&cp1, 0, 0, &err_code);
    set(&cp2, 0, 0, &err_code);
    complex_abs(&cp1, &err_code);

    if (read(&cp1))
        return 1;
    if (read(&cp2))
        return 1;

    struct complex_t cadd, csub, cmul, cdiv;
    add(&cp1, &cp2, &cadd);
    subtract(&cp1, &cp2, &csub);
    multiply(&cp1, &cp2, &cmul);
    int res = divide(&cp1, &cp2, &cdiv);

    show(&cadd);
    printf("\n");
    show(&csub);
    printf("\n");
    show(&cmul);
    printf("\n");
    if (res == 2)
        printf("Operation not permitted");
    else
        show(&cdiv);

    return 0;
}

