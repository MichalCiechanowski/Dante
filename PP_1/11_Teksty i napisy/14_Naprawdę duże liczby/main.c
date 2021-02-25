#include <stdio.h>
#include <stdlib.h>

#define nine ('0' + 1 + 2 + 2 + 2 + 2)

int DlugoscTekstu(const char* tekst);
int add(const char* number1, const char* number2, char* result, int size);
int CzyJestCyfra(char znak);
int validate(const char* number);
void Odwracanie(char* poczatek, char* koniec);


int main(){
    char numer1[201] = {0};
    char numer2[201] = {0};

    printf("Podaj pierwsza liczbe: ");
    if (scanf("%200s", numer1) == -1) {
        printf("Incorrect input");
        return 1;
    }

    while(getchar() != '\n');

    printf("Podaj druga liczbe: ");
    if (scanf("%200s", numer2) == -1) {
        printf("Incorrect input");
        return 1;
    }

    while(getchar() != '\n');

    if ((validate(numer1) != 1) || (validate(numer2) != 1)) {
        printf("Incorrect input");
        return 1;
    }
    char wynik[402] = {0};
    add(numer1, numer2, wynik, 202 + 100 + 100);

    printf("%s", wynik);

    return 0;
}

int DlugoscTekstu(const char* tekst)
{
    int dlugosc = 0;
    while (*tekst++ != '\0')
        dlugosc++;
    return dlugosc;
}

int CzyJestCyfra(char znak)
{
    if ((znak <= nine) && (znak >= '0') )
        return 1;
    return 0;
}

void Odwracanie(char* poczatek, char* koniec)
{
    char tmp;
    while (poczatek < koniec) {
        tmp = *poczatek;
        *poczatek++ = *koniec;
        *koniec-- = tmp;
    }
}

int validate(const char* number)
{   
    if (number == NULL){
        return -1;
    }
        
    
    int czyBylaRoznaOdZera = 0;

    while(*number != '\0') {
        if (!CzyJestCyfra(*number)){
             return 0;
        }
           
        if (*number != '0')
            czyBylaRoznaOdZera = 1;

        if (*number == '0' && *(number + 1) == '\0')
            return 1;

        if (*number == '0' && !czyBylaRoznaOdZera)
            return 0;
        number++;
    }
    return 1;
}

int add(const char* number1, const char* number2, char* result, int size)
{
    if ((validate(number2) != 1) || (validate(number1) != 1))
        return 1;
    
    if ((size <= 0) || (result == NULL))
        return 1;
    const char* numer1;
    const char* numer2;


    if (DlugoscTekstu(number2) < DlugoscTekstu(number1)) {
        numer1 = number2;
        numer2 = number1;
    }
    else {
        numer1 = number1;
        numer2 = number2;
    }

    int numer1_len = DlugoscTekstu(numer1);
    int numer2_len = DlugoscTekstu(numer2);
    
    int roznica = numer2_len - numer1_len;

    if (size < numer2_len)
        return 2;

    int reszta = 0;
    int p = 0;

    for (int i = numer1_len - 1; i >= 0; i--) {
        int suma = (*(numer1 + i) - '0') + (*(numer2 + i + roznica) - '0') + carry;
        *(result + p)= (suma % 10) + '0';
        reszta = suma / 10;

        p++;
    }

    for (int i = numer2_len - numer1_len - 1; i >= 0; i--) {
        int suma = (*(numer2 + i) - '0') + roznica;
        *(result + p) = (suma % 10) + '0';
        reszta = suma / 10;

        p++;
    }

    if (reszta) {
        *(result + p) = (char)reszta + '0';
        p++;
    }

    if (p == size)
        return 2;
  
    *(result + p) = '\0';

    int dlugoscWyniku = DlugoscTekstu(result);
    char* koniecWyniku = result + dlugoscWyniku;

 
    Odwracanie(result, koniecWyniku - 1);

    return 0;
}