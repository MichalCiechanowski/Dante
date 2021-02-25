#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"

int starts_with(const char* txt, const char* find) {
	if (txt == NULL || find == NULL)
		return -1;

	int txt_len = strlen(txt);
	int find_len = strlen(find);

	if (find_len > txt_len)
		return 0;
	
	if (*txt == '\0' || *find == '\0')
		return 1;

	if (*txt != *find)
		return 0;

	return starts_with(txt + 1, find + 1);
}

int ends_with(const char* txt, const char* find) {
	if (txt == NULL || find == NULL)
		return -1;
	
	if (*txt == '\0' || *find == '\0')
		return 1;

	int txt_len = strlen(txt);
	int find_len = strlen(find);

	if (find_len > txt_len)
		return 0;

	int diff = txt_len - find_len;
	if (*(txt + diff) != *find)
		return 0;

	return ends_with(txt + 1, find + 1);
}

void clear_newline() {
	char c = getchar();
	if (c != '\n')
		clear_newline();
}

int main() {
	char txt[102] = {0};
	char find[102] = {0};

	printf("Podaj tekst: \n");
	fgets(txt, 101, stdin);
	int len = strlen(txt);
	if (*(txt + len - 1) == '\n')
		*(txt + len - 1) = '\0';
	else
		clear_newline();

	printf("Podaj drugi tekst: \n");
	fgets(find, 101, stdin);
	len = strlen(find);
	if (*(find + len - 1) == '\n')
		*(find + len - 1) = '\0';
	else
		clear_newline();

	printf("%d\n", starts_with(txt, find));
	printf("%d\n", ends_with(txt, find));

	return 0;
}
