#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_palindrom(const char* text) {
	if (text == NULL)
		return -1;

	int len = strlen(text);

	if (len <= 1)
		return 0;

	const char* end = text + len - 1;
	const char* beg = text;
	while (beg < end) {
		if (*beg++ != *end--)
			return 0;
	}
	return 1;
}

int is_palindrom_len(const char* text, int len) {
	const char* end = text + len - 1;
	const char* beg = text;
	while (beg < end) {
		if (*beg++ != *end--)
			return 0;
	}
	return 1;
}

char* find_palindrom(char* text, int len) {
	if (text == NULL || len <= 0)
		return NULL;

	int length = strlen(text);
	for (int i = 0; i < length; i++) {
		if (is_palindrom_len(text + i, len) == 1) {
			if (*(text + i + len) != '\0')
				*(text + i + len) = '\0';
			return text + i;
		}
	}

	return NULL;
}

int create_palindrom(const char* text, char* out, int size) {
	if (text == NULL || out == NULL || size <= 0)
		return 1;

	int len = strlen(text);
	if (2 * len + 1 > size)
		return 2;

	for (int i = 0; i < len; i++) {
		*(out + i) = *(text + i);
		*(out + 2 * len - 1 - i) = *(text + i);
	}
	*(out + 2 * len) = '\0';

	return 0;
}

int main() {
	printf("Podaj tekst: ");
	char text[1002] = {0};
	char out[2001] = {0};
	fgets(text, 1001, stdin);
	int length = strlen(text);
	if (*(text + length - 1) == '\n')
		*(text + length - 1) = '\0';
	else
		while (getchar() != '\n');

	if (is_palindrom(text)) {
		printf("YES");
		return 0;
	}

	printf("NO\n");
	printf("Co dalej?\n");
	char choice;
	if (scanf("%c", &choice) != 1) {
		printf("Incorrect input");
		return 1;
	}
	if (!(choice == 'c' || choice == 'C' || choice == 'f' || choice == 'F')) {
		printf("Incorrect input data");
		return 2;
	}

	if (choice == 'c' || choice == 'C') {
		create_palindrom(text, out, 2001);
		printf("%s", out);
	}

	if (choice == 'f' || choice == 'F') {
		printf("Podaj wymagana dlugosc: ");
		int len;
		while (getchar() != '\n');
		if (scanf("%d", &len) != 1) {
			printf("Incorrect input");
			return 1;
		}
		if (len <= 0) {
			printf("Incorrect input data");
			return 2;
		}
		char* result = find_palindrom(text, len);
		if (result == NULL) {
			printf("Couldn't find");
			return 0;
		}
		printf("%s", result);
	}

	return 0;
}
