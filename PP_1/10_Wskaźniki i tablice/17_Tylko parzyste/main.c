#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "vector_utils.h"
#include "functions.h"

int main() {
    int tab[100] = {0};

    printf("Podaj liczby:");
    int size = read_vector(tab, 100, -1);
    if (size == 0) {
        printf("Not enough data available");
        return 3;
    } else if (size == -2) {
        printf("Incorrect input");
        return 1;
    }

    int number;
    number = get_next_number(tab, size, ALL_ODD);
    if (number == -1)
        printf("Nothing to show");

    int is_first = 1;
    while (number != -1) {
        if (is_first) {
            printf("%d", number);
            is_first = 0;
        }
        else
            printf(" %d", number);

        number = get_next_number(NULL, size, ALL_ODD);
    }

    printf("\n");

    number = get_next_number(tab, size, ALL_EVEN);
    if (number == -1)
        printf("Nothing to show");

    is_first = 1;
    while (number != -1) {
        if (is_first) {
            printf("%d", number);
            is_first = 0;
        }
        else
            printf(" %d", number);

        number = get_next_number(NULL, size, ALL_EVEN);
    }

    printf("\n");

    number = get_next_number(tab, size, MIX);
    if (number == -1)
        printf("Nothing to show");

    is_first = 1;
    while (number != -1) {
        if (is_first) {
            printf("%d", number);
            is_first = 0;
        }
        else
            printf(" %d", number);

        number = get_next_number(NULL, size, MIX);
    }
    
    return 0;
}