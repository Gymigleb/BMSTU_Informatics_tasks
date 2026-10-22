#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MIN_VAL -10
#define MAX_VAL 0
#define MAX_ROWS 5
#define MAX_COLS 10
#define DEL_VAL 0

int rdn() {return -1*(rand() % (MIN_VAL - 1));}


int main() {
	int arr[MAX_ROWS][MAX_COLS + 1];
	srand(time(NULL));

	printf("matrix:\n");
	for (int i = 0; i < MAX_ROWS; i++) {
		arr[i][MAX_COLS] = 0;
		for (int j = 0; j < MAX_COLS; j++) {
			arr[i][j] = rdn();
			printf("%3d ", arr[i][j]);
			if (arr[i][j] == DEL_VAL) {arr[i][MAX_COLS] = 1;}
		}
		putchar('\n');
	}

	// for (int i = 0; i < MAX_ROWS; i++) {printf("%d ", arr[i][MAX_COLS]);}
	
	for (int tar = 0; tar < MAX_ROWS; tar++) {
		if (arr[tar][MAX_COLS] == 0) {
			for (int i = 0; i < tar; i++) {
				if (arr[i][MAX_COLS] == 1) {
					for (int j = 0; j < MAX_COLS; j++) {arr[i][j] = arr[tar][j];}
					arr[tar][MAX_COLS] = 1;
					arr[i][MAX_COLS] = 0;
					break;
				}
			}
		}
	}

	for (int i = 0; i < MAX_ROWS; i++) {
		if (arr[i][MAX_COLS] == 1) {
			for (int j = 0; j < MAX_COLS; j++) {arr[i][j] = 0;}	
		}
	}
	
	printf("redacted matrix:\n");
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {printf("%3d ", arr[i][j]);}
		putchar('\n');
	}
	// for (int i = 0; i < MAX_ROWS; i++) {printf("%d ", arr[i][MAX_COLS]);}
}
