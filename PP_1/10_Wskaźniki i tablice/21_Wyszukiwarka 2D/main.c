#include <stdio.h>

int column_statistics(const int* ptr, int width, int height, int column_id,
                      int* max, int* min, float* avg) {
    if (ptr == NULL || width <= 0 || height <= 0 || column_id < 0 ||
        max == NULL || min == NULL || avg == NULL || column_id > width)
        return 1;

    *max = *(ptr + column_id);
    *min = *(ptr + column_id);
    *avg = 0;
    for (int i = 0; i < height; i++) {
        int val = *(ptr + i * width + column_id);
        if (val > *max)
            *max = val;
        if (val < *min)
            *min = val;
        *avg += val;
    }
    *avg /= height;

    return 0;
}

int row_statistics(const int* ptr, int width, int height, int row_id,
                      int* max, int* min, float* avg) {
    if (ptr == NULL || width <= 0 || height <= 0 || row_id < 0 ||
        max == NULL || min == NULL || avg == NULL || row_id > height)
        return 1;

    *max = *(ptr + width * row_id);
    *min = *(ptr + width * row_id);
    *avg = 0;
    for (int i = 0; i < width; i++) {
        int val = *(ptr + width * row_id + i);
        if (val > *max)
            *max = val;
        if (val < *min)
            *min = val;
        *avg += val;
    }
    *avg /= width;

    return 0;
}

int main() {
    int tab[5][5] = {0};
    printf("Podaj liczby:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int ret = scanf("%d", &tab[i][j]);
            if (ret != 1) {
                printf("Incorrect input");
                return 1;
            }
        }
    }

    const int* ptr = (int*)tab;
    int max;
    int min;
    float avg;
    for (int i = 0; i < 5; i++) {
        column_statistics(ptr, 5, 5, i, &max, &min, &avg); 
        printf("%d %d %.2f\n", min, max, avg);
    }
    for (int i = 0; i < 5; i++) {
        row_statistics(ptr, 5, 5, i, &max, &min, &avg); 
        printf("%d %d %.2f", min, max, avg);
        if (i != 4)
            printf("\n");
    }

    return 0;
}