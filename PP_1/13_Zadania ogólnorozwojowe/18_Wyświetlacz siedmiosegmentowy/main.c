#include <stdio.h>
#include <string.h>

char* numbers[10] = {
" _ "
"| |"
"|_|",

"   "
"  |"
"  |",

" _ "
" _|"
"|_ ",

" _ "
" _|"
" _|",

"   "
"|_|"
"  |",

" _ "
"|_ "
" _|",

" _ "
"|_ "
"|_|",

" _ "
"  |"
"  |",

" _ "
"|_|"
"|_|",

" _ "
"|_|"
" _|"
};

/*

 _   _   _       _   _   _  
  | |_|  _|  -  |_|   | |_  
  | |_| |_      |_|   | |_| 

*/

char res0[100] = {' '};
char res1[100] = {' '};
char res2[100] = {' '};
int p = 0;

void print_digit(int dig) {
    strncpy(res0 + p, numbers[dig] + 0, 3);
    strncpy(res1 + p, numbers[dig] + 3, 3);
    strncpy(res2 + p, numbers[dig] + 6, 3);
    res0[p + 3] = ' ';
    res1[p + 3] = ' ';
    res2[p + 3] = ' ';
    p += 4;
}

void print(int num) {
    int arr[25] = {0};
    int i = 0;

    if (num < 0) {
        num = -num;
        for (int k = 0; k < 4; k++) {
            res0[k] = ' ';
            res1[k] = ' ';
            res2[k] = ' ';
        }
        res1[1] = '-';
        p += 4;
    }

    if (num == 0) {
        print_digit(0);
    }

    while(num > 0) {
        int mod = num % 10;
        arr[i] = mod;
        i++;
        num = num / 10;
    }
    for (int j = i - 1; j > -1; j--)
        print_digit(arr[j]);
    
    res0[p] = '\n';
    res1[p] = '\n';

    res0[p + 1] = '\0';
    res1[p + 1] = '\0';

    res2[p] = '\0';

    printf("%s", res0);
    printf("%s", res1);
    printf("%s", res2);
}

int main() {
    char row0[100] = {' '};
    char row1[100] = {' '};
    char row2[100] = {' '};
    row0[99] = '\0';
    row1[99] = '\0';
    row2[99] = '\0';

    printf("Podaj dzialanie:\n");
    fgets(row0, 100, stdin);
    fgets(row1, 100, stdin);
    fgets(row2, 100, stdin);

    for (int i = 0; i < 100; i++) {
        if (row0[i] == '\n')
            row0[i] = ' ';
        if (row1[i] == '\n')
            row1[i] = ' ';
        if (row2[i] == '\n')
            row2[i] = ' ';
    }
    
    char nums[25][9] = {0};
    char znak;

    int nums_i = 0;
    for (int i = 0; i < 100; i += 4) {
        strncpy(nums[nums_i],     row0 + i, 3);
        strncpy(nums[nums_i] + 3, row1 + i, 3);
        strncpy(nums[nums_i] + 6, row2 + i, 3);
        nums_i++;
    }

    int num1 = 0;
    int num2 = 0;

    int poprzednie_i = 0;
    int byl_znak = 0;
    for (int i = 0; i < 25 && !byl_znak; i++) {
        int was_found = 0;
        for (int j = 0; j < 10 && !byl_znak; j++) {
            if (strncmp(nums[i], numbers[j], 9) == 0) {
                was_found = 1;
                num1 *= 10;
                num1 += j;
            }
        }
        if (!was_found) {
            znak = nums[i][4];
            poprzednie_i = i;
            byl_znak = 1;
        }
    }

    int koniec = 0;
    for (int i = poprzednie_i + 1; i < 25 && !koniec; i++) {
        int was_found = 0;
        for (int j = 0; j < 10 && !koniec; j++) {
            if (strncmp(nums[i], numbers[j], 9) == 0) {
                was_found = 1;
                num2 *= 10;
                num2 += j;
            }
        }
        if (!was_found) {
            koniec = 1;
        }
    }

    if (znak == '+')
        print(num1 + num2);
    if (znak == '-')
        print(num1 - num2);
    if (znak == '*')
        print(num1 * num2);
    if (znak == '/') {
        if (num2 == 0) {
            printf("Operation not permitted");
            return 4;
        }
        print(num1 / num2);
    }

    return 0;
}
