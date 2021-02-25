#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct point_t {
    int x;
    int y;
};

struct point_t* set(struct point_t* p, int x, int y) {
    if (p == NULL)
        return NULL;
    p->x = x;
    p->y = y;
    return p;
}

void show(const struct point_t* p) {
    if (p == NULL)
        return;
    printf("x = %d; y = %d\n", p->x, p->y);
}

struct point_t* read(struct point_t* p) {
    if (p == NULL)
        return NULL;
    
    printf("Podaj wspolrzedna x: ");
    if (scanf("%d", &p->x) != 1) {
        printf("Incorrect input");
        return NULL;
    }
    printf("Podaj wspolrzedna y: ");
    if (scanf("%d", &p->y) != 1) {
        printf("Incorrect input");
        return NULL;
    }
    return p;
}

float distance(const struct point_t* p1, const struct point_t* p2, int* err_code) {
    if (p1 == NULL || p2 == NULL) {
        if (err_code != NULL)
            *err_code = 1;
        return 0;
    }
    
    int x_diff = abs(p1->x - p2->x);
    int y_diff = abs(p1->y - p2->y);

    float result = sqrtf((float)(x_diff * x_diff + y_diff * y_diff));
    
    if (err_code != NULL)
        *err_code = 0;

    return result;
}

int main() {
    struct point_t p1;
    struct point_t p2;
    if (read(&p1) == NULL)
        return 1;

    srand((unsigned int)time(0));
    set(&p2, rand() % 200 - 100, rand() % 200 - 100);

    show(&p1);
    show(&p2);

    int err_code;
    printf("%.2f", distance(&p1, &p2, &err_code));

    return 0;
}
