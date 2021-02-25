#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct point_t {
    int x;
    int y;
};

struct segment_t {
    struct point_t start;
    struct point_t end;
};

struct point_t* read(struct point_t* p) {
    if (p == NULL)
        return NULL;
    
    printf("Enter X coordinate: ");
    if (scanf("%d", &p->x) != 1) {
        printf("Incorrect input");
        return NULL;
    }
    printf("Enter y coordinate: ");
    if (scanf("%d", &p->y) != 1) {
        printf("Incorrect input");
        return NULL;
    }
    return p;
}

struct segment_t* read_segment(struct segment_t* p) {
    if (p == NULL)
        return NULL;
    
    printf("Enter coordinates of the first point:\n");
    if (read(&p->start) == NULL)
        return NULL;
    printf("Enter coordinates of the second point:\n");
    if (read(&p->end) == NULL)
        return NULL;

    return p;
}

void show_segment(const struct segment_t* p) {
    if (!p)
        return;
    printf("Line start coords: x = %d; y = %d\n", p->start.x, p->start.y);
    printf("Line end coords: x = %d; y = %d\n", p->end.x, p->end.y);
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

float length(const struct segment_t* s, int* err_code) {
    int err = 0;
    float res = distance(&s->start, &s->end, &err);
    if (err == 1) {
        if (err_code) *err_code = 1;
        return -1;
    }
    if (err_code) *err_code = 0;
    return res;
}

int main() {
    struct segment_t s;
    if (read_segment(&s) == NULL)
        return 1;

    show_segment(&s);

    int err_code;
    printf("%.2f", length(&s, &err_code));

    return 0;
}


