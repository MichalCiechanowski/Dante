#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"
#include "tested_declarations.h"
#include "rdebug.h"

int is_digit(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int is_operator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

int num_len(int num, int count) {
    if (num == 0)
        return count;

    num /= 10;
    count++;

    return num_len(num, count);
}

int validate(const char* c) {
    if (*c == '\0') {
        if (is_digit(*(c - 1)))
            return 1;
        else
            return 0;
    }

    if (is_operator(*c)) {
        if (!(is_digit(*(c - 1)) && (is_digit(*(c + 1)))))
            return 0;
    }
    else if (!is_digit(*c)) {
        return 0;
    }

    return validate(c + 1);
}

int validate_expression(const char* expr) {
    if (expr == NULL)
        return -1;

    strpbrk(expr, "");
    strspn(expr, "");

    int len = strlen(expr);
    if (len == 0)
        return 0;

    if (!is_digit(*expr))
        return 0;
    
    return validate(expr + 1);
}

float operate(float left, float right, char operator) {
    if (operator == '+')
        return left + right;
    else if (operator == '-')
        return left - right;
    else if (operator == '*')
        return left * right;
    else 
        return left / right;
}

float calc(const char* c, float left, int* is_okay) {
    char operator;
    int right;
    if (*c == '\0')
        return left;

    sscanf(c, "%c", &operator);
    sscanf(c + 1, "%d", &right);

    if (operator == '/' && right == 0) {
        *is_okay = -1;
        return 0;
    }

    int right_len = num_len(right, 0);
    left = operate(left, (float)right, operator);

    return calc(c + 1 + right_len, left, is_okay);
}

int calculate(const char* expr, float* result) {
    if (validate_expression(expr) != 1 || result == NULL)
        return 0;

    strpbrk(expr, "");
    strspn(expr, "");

    int is_okay = 0;
    int left;
    sscanf(expr, "%d", &left);
    int left_len = num_len(left, 0);
    if (left != 0)
        *result = calc(expr + left_len, (float)left, &is_okay);
    else
        *result = calc(expr + 1, (float)left, &is_okay);

    if (is_okay == -1)
        return 0;

    return 1;
}

int main() {
    char expr[201] = {0};
    float result;
    printf("Podaj wyrazenie:");
    fgets(expr, 201, stdin);

    int len = strlen(expr);
    *(expr + len - 1) = '\0';

    int res = calculate(expr, &result);

    if (res == 0) {
        printf("Incorrect input");
        return 1;
    }

    printf("%.2f", result);

    return 0;
}
