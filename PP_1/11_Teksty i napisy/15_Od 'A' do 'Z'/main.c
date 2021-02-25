#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define LEN  91

void swap(const char** c1, const char** c2) 
{ 
    const char* temp = *c1; 
    *c1 = *c2; 
    *c2 = temp; 
} 
  
int sort(char const* ptrs[], int size) {
    if (ptrs == NULL || size <= 0)
        return 1;

    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (strcmp(*(ptrs + j), *(ptrs + j + 1)) > 0)
                swap(ptrs + j, ptrs + j + 1);

    return 0;
}

int main() {
    char* titles[SIZE] = {0};

    for (int i = 0; i < SIZE; i++)
        *(titles + i) = malloc(sizeof(char) * LEN);

    printf("Podaj tytuly:\n");
    int title_count = 0;
    while (title_count < SIZE) {
        fgets(*(titles + title_count), LEN, stdin);
        int len = strlen(*(titles + title_count));
        if (len == LEN - 1 && *(*(titles + title_count) + len - 1) != '\n')
            while (getchar() != '\n');
        if (*(*(titles + title_count) + len - 1) == '\n')
            *(*(titles + title_count) + len - 1) = '\0';
        if (**(titles + title_count) == '\0')
            break;
        title_count++;
    }

    if (title_count == 0) {
        for (int i = 0; i < SIZE; i++)
            free(*(titles + i));
        printf("Not enough data available");
        return 3;
    }

    char const** ptrs = (char const**)titles;
    sort(ptrs, title_count);

    for (int i = 0; i < title_count; i++) {
        printf("%s", *(titles + i));
        if (i != title_count - 1)
            printf("\n");
    }

    for (int i = 0; i < SIZE; i++)
        free(*(titles + i));

    return 0;
}