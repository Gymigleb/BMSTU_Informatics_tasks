// ex 3, p. 67

#include <stdio.h>
#include <string.h> // for strcmp and strcpy
#include <stdlib.h>
#include <stdbool.h>

#define nn 20

// base struct
struct sport {
	char fam[30]; // surname
	char stran[30]; // country
	int k; // num of grades
	float oc[5]; // arr of grades
	float sr; // mid grade
};

// result struct
struct res{
	char stran[30]; // country
	float s; // sum of mid grades
};

// prototypes of fync
void wwod(int *n, struct sport a[]);
void wiwod(int n, struct sport a[]);
void upor(int n, struct sport a[]);
void pobed(int n, struct sport a[], struct res *max);

int main() {
	int n;
	struct sport a[nn];
	struct res max;

	wwod(&n, a); // get data
	
	upor(n, a); // sort
	
	printf("structs after sort:\n");
	wiwod(n, a); // type data after sorting
	
	pobed(n, a, &max); // search for winner
	
	printf("\n\ncountry of winner - %s\n", max.stran);
	printf("mid grade of winner is %6.2f\n", max.s);
	
	while (getchar() != '\n');
	getchar();	

	return 0;
}

void wwod(int *n, struct sport a[]) {
	printf("type num of structs: ");
	scanf("%d", n);

	while (getchar() != '\n');

	printf("type struct's data\n");
	for (int i = 0; i < *n; i++) {
		printf("\ntype surname: ");
		scanf("%s", a[i].fam);

		printf("\ntype country: ");
		scanf("%s", a[i].stran);

		printf("type num of grades: ");
		scanf("%d", &a[i].k);

		printf("type grades: ");
		a[i].sr = 0;

		for (int j = 0; j < a[i].k; j++) {
			scanf("%f", &a[i].oc[j]);
			a[i].sr += a[i].oc[j];
		}

		a[i].sr /= a[i].k; // calc mid grade
	}
}

void wiwod(int n, struct sport a[]) {
	for (int i = 0; i < n; i++) {
		printf("surname: %s\n", a[i].fam);
		printf("county: %s\n", a[i].stran);
		printf("num of grades: %2d\n", a[i].k);
		printf("grades: ");
		for (int j = 0; j < a[i].k; j++) {
			printf("%6.2f ", a[i].oc[j]);
		}
		printf("\nmid grade: %6.2f\n", a[i].sr);
		printf("---------------------\n");
	}
}

// sort func (buble)
void upor(int n, struct sport a[]) {
	int k = 0;
	bool flag;

	struct sport b; // temporary struct to manage data
	
	do {
		flag = false;
		k++;
		for (int i = 0; i < n - k; i++) {
			// if current element lower than next
			if (a[i].sr < a[i+1].sr) {
				// swap them
				b = a[i];
				a[i] = a[i+1];
				a[i + 1] = b;
				flag = true; // swap was
			}
		}
	} while (flag); // if swap was not - arr sorted
}

// fync of search winner's country
void pobed(int n, struct sport a[], struct res *max) {
	int kol = -1; // last added country to b
	struct res b[nn];
	bool flag;

	// make arr of unque countries and sum its's grades
	for (int i = 0; i < n; i++) {
		int j = 0;
		flag = true; // true - country not find in arr yet
		
		// find it
		while ((j <= kol) && flag) {
			if (strcmp(a[i].stran, b[j].stran) == 0) {
				flag = false; // countri finded
				b[j].s += a[i].sr; // add grade to country's sum
			}
			else {j++;}
		}

		// if while was ended, and flag is up (true) - corrent country not in arr
		if (flag) {
			kol++;
			strcpy(b[kol].stran, a[i].stran); // copy name of country
			b[kol].s = a[i].sr;
		}
	}

	// find country with max sum of grades
	max->s = -1; // grades can't be lower than 0
	for (int i = 0; i <= kol; i++) {
		if (b[i].s > max->s) {
			*max = b[i]; // copy struct of winner
		}
	}

	// type sum for all countries
	for (int i = 0; i <= kol; i++) {
		printf("\ncountry - %s, sum of mid grades = %6.2f", b[i].stran, b[i].s);
	}	
}
