#include <stdio.h>

struct byte_t {
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;
	unsigned char bit8 : 1;
};

union bit_set {
	unsigned int u;
	unsigned short s[2];
	unsigned char b[4];
	struct byte_t bits[4];
	};

int main() {
	union bit_set bs;
	printf("Podaj liczbe: ");
	if (scanf("%u", &bs.u) != 1) {
		printf("Incorrect input");
		return 1;
	}

	printf("%u\n", bs.u);

	printf("%u", *(bs.s + 0));
	printf(" ");
	printf("%u", *(bs.s + 1));
	printf("\n");

	printf("%u", *(bs.b + 0));
	printf(" ");
	printf("%u", *(bs.b + 1));
	printf(" ");
	printf("%u", *(bs.b + 2));
	printf(" ");
	printf("%u", *(bs.b + 3));

	printf("\n");

	printf("%d", (*(bs.bits + 0)).bit8);
	printf("%d", (*(bs.bits + 0)).bit7);
	printf("%d", (*(bs.bits + 0)).bit6);
	printf("%d", (*(bs.bits + 0)).bit5);
	printf("%d", (*(bs.bits + 0)).bit4);
	printf("%d", (*(bs.bits + 0)).bit3);
	printf("%d", (*(bs.bits + 0)).bit2);
	printf("%d", (*(bs.bits + 0)).bit1);

	printf(" ");

	printf("%d", (*(bs.bits + 1)).bit8);
	printf("%d", (*(bs.bits + 1)).bit7);
	printf("%d", (*(bs.bits + 1)).bit6);
	printf("%d", (*(bs.bits + 1)).bit5);
	printf("%d", (*(bs.bits + 1)).bit4);
	printf("%d", (*(bs.bits + 1)).bit3);
	printf("%d", (*(bs.bits + 1)).bit2);
	printf("%d", (*(bs.bits + 1)).bit1);

	printf(" ");

	printf("%d", (*(bs.bits + 2)).bit8);
	printf("%d", (*(bs.bits + 2)).bit7);
	printf("%d", (*(bs.bits + 2)).bit6);
	printf("%d", (*(bs.bits + 2)).bit5);
	printf("%d", (*(bs.bits + 2)).bit4);
	printf("%d", (*(bs.bits + 2)).bit3);
	printf("%d", (*(bs.bits + 2)).bit2);
	printf("%d", (*(bs.bits + 2)).bit1);

	printf(" ");

	printf("%d", (*(bs.bits + 3)).bit8);
	printf("%d", (*(bs.bits + 3)).bit7);
	printf("%d", (*(bs.bits + 3)).bit6);
	printf("%d", (*(bs.bits + 3)).bit5);
	printf("%d", (*(bs.bits + 3)).bit4);
	printf("%d", (*(bs.bits + 3)).bit3);
	printf("%d", (*(bs.bits + 3)).bit2);
	printf("%d", (*(bs.bits + 3)).bit1);



	return 0;
}
