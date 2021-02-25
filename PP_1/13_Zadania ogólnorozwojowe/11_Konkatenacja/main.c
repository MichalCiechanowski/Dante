#include <stdio.h>
#include <stdlib.h>

int numlen(int n) {
	int count = 0;
	while (n != 0) {
        n /= 10;
        count++;
    }
	return count;
}

int cmp(int** tab, int* lens, int x, int y) {
	int lx = lens[x];
	int ly = lens[y];
	int lmin = lx < ly ? lx : ly;
	for (int i = 0; i < lmin; i++) {
		if (tab[x][i] < tab[y][i])
			return 1;
		else if (tab[x][i] > tab[y][i])
			return 0;
	}

	int vec1[100] = {0};
	int vec2[100] = {0};
	int p = 0;
	for (int i = 0; i < lx; i++)
		vec1[p++] = tab[x][i];
	for (int i = 0; i < ly; i++)
		vec1[p++] = tab[y][i];
	p = 0;
	for (int i = 0; i < ly; i++)
		vec2[p++] = tab[y][i];
	for (int i = 0; i < lx; i++)
		vec2[p++] = tab[x][i];

	for (int i = 0; i < lx + ly; i++) {
		if (vec1[i] < vec2[i])
			return 1;
		else if (vec1[i] > vec2[i])
			return 0;
	}

	if (lx < ly)
		return 1;

	return 0;
}

void swap(int** tab, int* lens, int x, int y) {
	int* tmp = tab[x];
	tab[x] = tab[y];
	tab[y] = tmp;
	int tmp2 = lens[x];
	lens[x] = lens[y];
	lens[y] = tmp2;
}

int main() {
	int vec[1000] = {0};
	int lens[1000] = {0};
	int count = 0;
	printf("Podaj liczby:\n");
	int should_continue = 1;
	int p = 0;
	while (should_continue) {
		int x;
		int err = scanf("%d", &x);
		if (err != 1) {
			printf("Incorrect input");
			return 1;
		}
		if (x == 0) {
			if (p == 0) {
				printf("Not enough data available");
				return 3;
			}
			count = p;
			should_continue = 0;
		}
		if (p < 1000) {
			vec[p] = x;
			lens[p] = numlen(x);
			p++;
		}
	}

	int** tab = malloc(count * sizeof(int*));
	for (int i = 0; i < count; i++) {
		tab[i] = malloc(lens[i] * sizeof(int));

		int num = vec[i];
		int j = lens[i] - 1;
		while (num != 0) {
			tab[i][j] = num % 10;
			num /= 10;
			j--;
		}
	}

	for (int i = 0; i < count - 1; i++)
		for (int j = 0; j < count - i - 1; j++)
			if (cmp(tab, lens, j, j + 1))
              swap(tab, lens, j, j + 1); 

	for (int i = 0; i < count; i++)
		for (int j = 0; j < lens[i]; j++)
			printf("%d", tab[i][j]);

	for (int i = 0; i < count; i++)
		free(tab[i]);
	free(tab);

	return 0;
}