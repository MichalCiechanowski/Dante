#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vector_utils.h"

int find(const int* tab, int size, int to_find) {
    static const int* last_tab = NULL;
    static int last_size = 0;
    static int index = 0;

    if (tab != NULL) {
        last_tab = tab;
        last_size = size;
        index = 0;
    }
    if (last_tab == NULL)
        return -2;
    if (last_size <= 0)
        return -2;

    int number;
    if (index != last_size)
        number = *(last_tab + index++);
    else
        return -1;

    if (number == to_find)
        return index - 1;
    else
        return find(NULL, last_size, to_find);

    return 0;
}

int main() {
    int tab[100] = {0};

    printf("Podaj liczby:");
    int size = read_vector(tab, 100, 0);
    if (size == 0) {
        printf("Not enough data available");
        return 3;
    } else if (size == -2) {
        printf("Incorrect input");
        return 1;
    }
    while (getchar() != '\n');

    printf("podaj element ktory chcesz znalezc\n");
    int to_find;
    if (scanf("%d", &to_find) == 0) {
        printf("Incorrect input");
        return 1;
    }

    int index = find(tab, size, to_find);
    int is_first = 1;
    while (index != -1) {
         if (is_first) {
            printf("%d", index);
            is_first = 0;
        }
        else
            printf(" %d", index);

        index = find(NULL, 0, to_find);
    }
    if (is_first == 1)
        printf("Nothing to show");

    return 0;
}