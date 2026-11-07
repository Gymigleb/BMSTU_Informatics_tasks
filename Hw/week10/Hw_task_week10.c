#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 18

void input(int *r, int *c, char *a); // func for reading user data
void output(int r, int c, char *a, int f); // func for printing matrix
int max(int a, int b); // just max
int clus(char *str, int l); // func for counting max length of unalpha string
int comp(const void *srtA, const void *strB); // func to compare strings (needed in qsort)

int main() {
	int num_rows, num_cols;
	char arr[MAX_ROWS][MAX_COLS+1];

	input(&num_rows, &num_cols, &arr[0][0]);

	printf("\nyour matrix is:\n");
	output(num_rows, num_cols, &arr[0][0], 0);
	
	// calculating max length of unalpha sring for every string
	for (int i = 0; i < num_rows; i++) {
		arr[i][MAX_COLS] = (char) clus(&arr[i][0], num_cols);
	}

	printf("\nresult of calc lens:\n");
	output(num_rows, num_cols, &arr[0][0], 1);

	qsort(&arr[0][0], num_rows, sizeof(char)*(MAX_COLS+1), comp);

	printf("\nsorted matrix is:\n");
	output(num_rows, num_cols, &arr[0][0], 1);
	return 0;
}

int comp(const void *strA, const void *strB) {
	int A = (int)(((char *)strA)[MAX_COLS]);
	int B = (int)(((char *)strB)[MAX_COLS]);
	if (A == B) return 0;
	if (A > B) return +1;
	if (A < B) return -1;
}

void input(int *r, int *c, char *a) {
	printf("type num of rows[1, %d]: ", MAX_ROWS);
	while (scanf("%d", r) != 1 || *r < 1 || *r > MAX_ROWS) {
		printf("Error by inserting num of rows\n");
		while (getchar() != '\n');
		printf("type num of rows[1, %d]: ", MAX_ROWS);
	}
	while (getchar() != '\n');

	printf("type num of cols[1, %d]: ", MAX_COLS);
	while (scanf("%d", c) != 1 || *c < 1 || *c > MAX_COLS) {
		printf("Error by inserting num of cols\n");
		while (getchar() != '\n');
		printf("type num of cols[1, %d]: ", MAX_COLS);
	}
	while (getchar() != '\n');

	for (int i = 0; i < *r; i++) {
		printf("write %d str: ", i+1);
		for (int j = 0; j < *c; j++) {a[i*(MAX_COLS+1) + j] = getchar();}
		while (getchar() != '\n');
	}
}

void output(int r, int c, char *a, int f) {
	for (int i = 0; i < r; i++) {
		printf("str %d: ", i+1);
		for (int j = 0; j < c; j++) {printf("%c", a[i*(MAX_COLS+1) + j]);}
		if (f) {printf("   len of unalpha str = %d", a[i*(MAX_COLS+1) + (MAX_COLS)]);}
		putchar('\n');
	}
}

int max(int a, int b) {return (a > b) ? a : b;}

int clus(char *str, int l) {
	//Count max Len of Unalpha String 
	int cnt = 0;
	int Mcnt = 0;
	for (int i = 0; i < l; i++) {
		if (!isalpha(str[i])) {cnt++;}
		else {
			Mcnt = max(Mcnt, cnt);
			cnt = 0;
		}
	}
	return max(Mcnt, cnt);
}
