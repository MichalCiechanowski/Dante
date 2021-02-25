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
           if (str_cmp_i(words[j], words[j + 1]) > 0)
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
    char tab2[1001] = "If A clUTtered desk is A siGn oF A cLUTTeRED mINd oF What tHEN iS AN emPTy desk a sign  LAuReNCe J PetEr sIGn";
    sort_alphabetically(tab2);

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