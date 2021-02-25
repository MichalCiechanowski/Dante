#include <stdio.h>

void print(char c, int times) {
    for (int i = 0; i < times; i++)
        printf("%c", c);
}

void print_wiatrak(int n) {
    if (n >= 1) {
        for (int i = 0; i < n; i++) {
            print('X', i + 1);
            print(' ', n - i - 1);
            print('X', n - i);
            printf("\n");
        }
        for (int i = 0; i < n; i++) {
            print(' ', n - i - 1);
            print('X', i + 1);
            print(' ', i);
            print('X', n - i);
            printf("\n");
        }
    } else {
        n = -n;
        for (int i = 0; i < n; i++) {
            print(' ', i);
            print('X', n - i);
            print(' ', n - i - 1);
            print('X', i + 1);
            printf("\n");
        }
        for (int i = 0; i < n; i++) {
            print('X', n - i);
            print(' ', i);
            print('X', i + 1);
            printf("\n");
        }
    }
}

int main() {
    int tab[1000] = { 0 };
    int n = 0;
    while (1) {
        int x;
        printf("Podaj liczbe: ");
        scanf("%d", &x);
        if (x == 0)
            break;
        tab[n] = x;
        n++;
    }
    for (int i = 0; i < n; i++) {
        print_wiatrak(tab[i]);
        printf("\n");
    }

    return 0;
}
