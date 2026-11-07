// ex 1.2 char arrs
#include <stdio.h>
#include <stdbool.h>

const int NN = 15;

void wwod(int nn, int *m, int *n, char *a);
void wiwod(int nn, int m, int n, char *a);
bool simmetr(char *a, int n);

int main() {
	const int MM = 10;
	char a[MM][NN];
	int i, j, m, n;
	
	// insert size of matrix
	wwod(NN, &m, &n, &a[0][0]);

	// display matrix
	printf("\nmatrix:\n");
	wiwod(NN, m, n, &a[0][0]);

	// displaing of rows with checking
	printf("\nmatrix with showing it's simmetry\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			putchar(a[i][j]);
		}

		if (simmetr(a[i], n)) {printf("   sim = true\n");}
		else {printf("   sim = false\n");}
	}
	return 0;
}

void wwod(int nn, int *m, int *n, char *a) {
	int i, j;
	printf("type num of rows and cols of matrix: ");
	while (scanf("%d %d", m, n) != 2 || *m < 1 || *m > 10 || *n < 1 || *n > nn) {
		printf("error! type rows in range[1-10] and cols in range[1-%d]: ", nn);
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	printf("type matrix (you have to type only %d symbols in a row): \n", *n);
	for (int i = 0; i < *m; i++) {
		for (int j = 0; j < *n; j++) {
			// check element [i][j] by using one dimencion pointer
			// i * nn - jump through i rows. +j to moove in row.
			a[i * nn + j] = getchar();
		}
		while (getchar() != '\n');
	}
}

void wiwod(int  nn, int m, int n, char *a) {
	int i, j;
	printf("num of rows: %d\nnum of cols: %d\n", m, n);
	printf("matrix:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			putchar(a[i * nn + j]);
		}
		printf("\n");
	}
}

bool simmetr(char *a, int n) {
	int i = 0;

	// go from the start a[i] and from the end a[n-i-1], face to face.
	// i <= n/2 set edge of our check (middle of arr)
	while (a[i] == a[n - i - 1] && i <= n/2) {i++;}

	// if we stop after then we get on middle of arr,
	// arr not symmetric
	if (i <= n/2) {return false;}
	else {return true;}
}
