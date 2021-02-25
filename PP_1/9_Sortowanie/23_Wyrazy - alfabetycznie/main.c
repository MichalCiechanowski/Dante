#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int word_length(char* p)
{
    int word_len = 0;
    while (!(*p == '\0' || *p == ' ')) {
        word_len++;
        p++;
    }
    return word_len;
}

void swap(char** a, char** b)
{
    char* tmp = *a;
    *a = *b;
    *b = tmp;
}

int is_input_valid(char* text)
{
    while (*text != '\0') {
        if (isalpha(*text) == 0 && *text != ' ')
            return 0;
        text++;
    }
    return 1;
}

int sort_alphabetically(char tab[])
{
    if (tab == NULL)
        return 1;
    
    if (!is_input_valid(tab))
        return 1;


    char* p = tab;
    int word_count = 0;
    while (*p != '\0') {
        if (isalpha(*p) != 0 && (*(p + 1) == '\0' || *(p + 1) == ' '))
            word_count++;
        p++;
    }


    p = tab;

    char** words = malloc(word_count * sizeof(char*));

    for (int i = 0; i < word_count; i++) {
        
        while (*p == ' ') p++; 
        int word_len = word_length(p);
        words[i] = malloc((word_len + 1) * sizeof(char));
        memcpy(words[i], p, word_len);
        words[i][word_len] = '\0';
        p += word_len + 1;
    }

    
    for (int i = 0; i < word_count - 1; i++)
       for (int j = 0; j < word_count - i - 1; j++)
           if (strcmp(words[j], words[j + 1]) > 0)
              swap(&words[j], &words[j + 1]);

    p = tab;

    for (int i = 0; i < word_count; i++) {
        strcpy(p, words[i]);
        p += word_length(words[i]);
        *p = ' ';
        p++;
    }
    
    *(p - 1) = '\0';

    
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    
    free(words);

    return 0;
}

int main()
{
    char tab[1001] = {0};

    printf("Podaj tekst:\n");
    scanf("%1000[^\n]s", tab);

    int err_code = sort_alphabetically(tab);

    if (err_code == 1) {
        printf("Incorrect input data");
        return 2;
    }

    printf("%s", tab);

    return 0;
}