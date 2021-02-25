#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int numlen(int n) {
    int count = 0;
    if (n == 0)
        return 1;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

/*

    690
   4984
-------
   2760
  5520 
 6210  
2760   
-------
3438960

*/

#define VAL(p, i) *((p) + (i))
#define CHAR_TO_INT(exp) ((exp) - '0')
#define INT_TO_CHAR(exp) ((exp) + '0')

void
odwracanie(char* poczatek, char* koniec) {
    char znak;
    while (koniec > poczatek) {
        znak = VAL(koniec, 0);
        VAL(koniec--, 0) = *poczatek;
        VAL(poczatek++, 0) = znak;
    }
}

int
add(const char* number1, const char* number2, char* result, int size) {
    if (number1 == NULL || number2 == NULL || result == NULL || size <= 0)
        return 1;

    int dlugosc1 = 0;
    int dlugosc2 = 0;
    const char* numer1 = NULL;
    const char* numer2 = NULL;
    int reszta = 0;
    int x = 0;
    int suma = 0;
    int roznica = 0;
    
    dlugosc1 = strlen(number1);
    dlugosc2 = strlen(number2);

    if (dlugosc1 > size || dlugosc2 > size)
        return 2;

    roznica = dlugosc1 - dlugosc2;

    if (roznica >= 0) {
        numer1 = number1;
        numer2 = number2;
    } else {
        numer1 = number2;
        numer2 = number1;
        dlugosc2 = dlugosc1;
        roznica = -roznica;
    }

    int pierwsza_czesc = dlugosc2 - 1;
    for (int i = pierwsza_czesc; i >= 0; i--) {
        suma = CHAR_TO_INT(VAL(numer1, i + roznica)) + CHAR_TO_INT(VAL(numer2, i));
        suma += reszta;
        reszta = suma / 10;
        VAL(result, x) = INT_TO_CHAR(suma % 10);
        x++;
    }

    int druga_czesc = roznica - 1;
    for (int i = druga_czesc; i >= 0; i--) {
        suma = CHAR_TO_INT(VAL(numer1, i));
        suma += reszta;
        reszta = suma / 10;
        VAL(result, x) = INT_TO_CHAR(suma % 10);
        x++;
    }

    if (reszta != 0) {
        VAL(result, x) = INT_TO_CHAR(reszta);
        x++;
    }

    char* koniec = result + x - 1;
    char* poczatek = result;
    odwracanie(poczatek, koniec);

    if (x == size)
        return 2;
    else
        VAL(result, x) = '\0';

    return 0;
}


int main() {
    int n1, n2;
    printf("Podaj liczbe: ");
    scanf("%d", &n1);
    printf("Podaj liczbe: ");
    scanf("%d", &n2);


    int l1 = numlen(n1);
    int l2 = numlen(n2);

    int* t1 = malloc(l1 * sizeof(int));
    for (int i = 0; i < l1; i++)
        t1[i] = 0;
    int k = l1 - 1;
    int num = n1;
    while (num != 0) {
        if (k >= 0)
            t1[k] = num % 10;
        num /= 10;
        k--;
    }

    int* t2 = malloc(l2 * sizeof(int));
    for (int i = 0; i < l2; i++)
        t2[i] = 0;
    k = l2 - 1;
    num = n2;
    while (num != 0) {
        if (k >= 0)
            t2[k] = num % 10;
        num /= 10;
        k--;
    }

    char number1[400] = {0};
    for (int i = 0; i < l1; i++)
        number1[i] = t1[i] + '0';

    char result[400] = {0};
    char aaa[400] = {0};
    strncpy(aaa, number1, 400);
    for (int i = 0; i < n2 - 1; i++) {
        add(number1, aaa, result, 400);
        strncpy(number1, result, 400);
    }
    int max_len = strlen(result);

    int spc1 = max_len - l1;
    int spc2 = max_len - l2;
    for (int i = 0; i < spc1; i++)
        printf(" ");
    printf("%d\n", n1);

    for (int i = 0; i < spc2; i++)
        printf(" ");
    printf("%d\n", n2);

    for (int i = 0; i < max_len; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < l2; i++) {
        int x = n1 * t2[l2 - i - 1];
        int lx = numlen(x);
        int spcx = max_len - lx - i;
        for (int j = 0; j < spcx; j++)
            printf(" ");
        printf("%d\n", x);
    }

    for (int i = 0; i < max_len; i++)
        printf("-");

    printf("\n");
    printf("%s", result);

    free(t1);
    free(t2);

    return 0;
}