#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20
#define LEN 31

int is_input_valid(char* text)
{
    while (*text != '\0') {
        if (isalpha(*text) == 0)
            return 0;
        text++;
    }
    return 1;
}

int str_cmp_i(char* a, char* b)
{
    char* a_original = a;
    char* b_original = b;

    while (!(*a == '\0' || *b == '\0')) {
        char a_val = *a;
        char b_val = *b;
        if (isupper(*a))
            a_val = *a + 32;
        if (isupper(*b))
            b_val = *b + 32;
        if (a_val < b_val)
            return -1;
        else if (a_val > b_val)
            return 1;
        a++;
        b++;
    }
    if (*a == '\0' && *b == '\0')
        return strcmp(a_original, b_original);
    else if (*a == '\0')
        return -1;
    else
        return 1;
}

int sort_names_alphabetically(char names[SIZE][LEN], int size)
{
    if (names == NULL || size <= 0)
        return 1;

    for (int i = 0; i < size; i++)
        if (!is_input_valid(names[i]))
            return 1;

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (str_cmp_i(names[j], names[j + 1]) > 0) {
                char tmp[LEN];
                strcpy(tmp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tmp);
            }

    return 0;
}

int main()
{
    char names[SIZE][LEN] = {0};

    printf("Podaj imiona:\n");
    strcpy(names[0], "Michal");
    int name_count = 1;
    while (name_count < 20) {
        fgets(names[name_count], LEN, stdin);
        int len = strlen(names[name_count]);
        if (len == LEN - 1 && names[name_count][len - 1] != '\n')
            while (getchar() != '\n');
        if (names[name_count][len - 1] == '\n')
            names[name_count][len - 1] = '\0';
        if (*names[name_count] == '\0')
            break;
        name_count++;
    }

    int err_code = sort_names_alphabetically(names, name_count);

    if (err_code == 1) {
        printf("Incorrect input data");
        return 2;
    }

    for (int i = 0; i < name_count; i++) {
        printf("%s", names[i]);
        if (i != name_count - 1)
            printf("\n");
    }

    return 0;
}