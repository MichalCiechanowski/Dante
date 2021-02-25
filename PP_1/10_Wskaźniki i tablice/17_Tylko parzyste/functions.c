#include "functions.h"

#include <stdio.h>

int all_even(int number) {
    if (number == 0)
        return 1;

    int rem = number % 10; 
    if (rem % 2 != 0) 
        return 0; 
    number = number / 10; 

    return all_even(number);
}

int all_odd(int number) {
    if (number < 0)
        number = -number;
    if (number < 10) {
        int rem = number % 10; 
        if (rem % 2 != 0)
            return 1;
        else
            return 0;
    }

    int rem = number % 10; 
    if (rem % 2 == 0) 
        return 0; 
    number = number / 10; 

    return all_odd(number);
}

int get_next_number(const int* tab, int size, enum type t) {
    if (t < 0 || t > 2)
        return -2;

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

    if (t == ALL_EVEN) {
        if (all_even(number))
            return number;
        else
            return get_next_number(NULL, last_size, t);
    }
    else if (t == ALL_ODD) {
        if (all_odd(number))
            return number;
        else
            return get_next_number(NULL, last_size, t);
    }
    else if (t == MIX) {
        if (!(all_even(number) || all_odd(number)))
            return number;
        else
            return get_next_number(NULL, last_size, t);
    }

    return 0;
}

