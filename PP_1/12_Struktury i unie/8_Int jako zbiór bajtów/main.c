#include <stdio.h>
#include "byte_set.h"
#include "tested_declarations.h"
#include "rdebug.h"

/*
Jak z wyswietlonych bajtow 68 67 66 65 powstaje wartosc 1094861636?

   Bajty te sa przesuniete o kolejno 0, 8, 16, i 24 bity w prawo, a 
   poniewaz bajt to 8 bitow, to te 4 bajty pokryja miejsce o rozmiarze
   32 bitow, czyli tyle co int. Po sczytaniu tego int'a otrzymujemy 
   koncowy wynik.

Jak nazywa sie kolejnosc 68 67 66 65 i 65 66 67 68?
 
   Little Endian i Big Endian

*/ 

int main() {
	union byte_set bs;
	printf("Podaj liczbe: ");
	if (scanf("%d", &bs.i) != 1) {
		printf("Incorrect input");
		return 1;
	}

	for (int i = 0; i < 4; i++) {
		printf("%d", *(bs.b + i));
		if (i != 3)
			printf(" ");
	}

	return 0;
}

