#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 20
#define LEN 101

int str_cmp_i(char* a, char* b) {
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

int sort_titles_alphabetically(char titles[SIZE][LEN], int size) {
    if (titles == NULL || size <= 0 || size > SIZE)
        return 1;

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (str_cmp_i(titles[j], titles[j + 1]) > 0) {
                char tmp[LEN];
                strcpy(tmp, titles[j]);
                strcpy(titles[j], titles[j + 1]);
                strcpy(titles[j + 1], tmp);
            }

    return 0;
}

int main() {
    char titles[SIZE][LEN] = {0};

    printf("Podaj tytuly:\n");
    int title_count = 0;
    while (title_count < 20) {
        fgets(titles[title_count], LEN, stdin);
        int len = strlen(titles[title_count]);
        if (len == LEN - 1 && titles[title_count][len - 1] != '\n')
            while (getchar() != '\n');
        if (titles[title_count][len - 1] == '\n')
            titles[title_count][len - 1] = '\0';
        if (*titles[title_count] == '\0')
            break;
        title_count++;
    }

    int err_code = sort_titles_alphabetically(titles, title_count);

    if (err_code == 1) {
        printf("Incorrect input data");
        return 2;
    }

    for (int i = 0; i < title_count; i++) {
        printf("%s", titles[i]);
        if (i != title_count - 1)
            printf("\n");
    }

    return 0;
}