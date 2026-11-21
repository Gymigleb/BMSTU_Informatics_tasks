//libraries//libraries//libraries//libraries//libraries//libraries//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//libraries//libraries//libraries//libraries//libraries//libraries//


//defines//defines//defines//defines//defines//defines//defines//

#define MAX_LAGUAGE_WEIGHT 10
#define OVERWEIGHT_PRICE 100
#define MAX_NUMBER_OF_LAGUAGE 2

//defines//defines//defines//defines//defines//defines//defines//


//stucts//stucts//stucts//stucts//stucts//stucts//stucts//stucts//

typedef struct {
	char surname[64];
	int laguage_weight;
	int num_of_laguage;
	int add_payment;
} passenger;

//stucts//stucts//stucts//stucts//stucts//stucts//stucts//stucts//


//fync_def//fync_def//fync_def//fync_def//fync_def//fync_def//

void clear_input_buffer(); // removes '\n' and 'ctrl+d' from input buffer 
void input_num_p(int *num_p); // get num of passengers
void input(passenger *arr, int num_p); // get info about passengers
void print_passenger(passenger p);
void print_passengers(passenger *arr, int n);
int comp(const void * A, const void *B);

//fync_def//fync_def//fync_def//fync_def//fync_def//fync_def//


//main//main//main//main//main//main//main//main//main//main//

int main() {
	int num_p; // number of passengers
	int num_ovw; // number of passengers with laguage overweight
	int num_ovn; // number of passengers with to much number of laguage

	input_num_p(&num_p);

	passenger base[num_p]; // first
	passenger overweight[num_p]; // second
	passenger overnum[num_p]; // third

	input(&base[0], num_p);
	
	printf("base passengers:\n");
	print_passengers(&base[0], num_p);
	
	// fill arrs 2 and 3
	for (int i = 0; i < num_p; i++) {
		if (base[i].add_payment != 0) {
			overweight[num_ovw] = base[i];
			num_ovw++;
		}
		if (base[i].num_of_laguage > MAX_NUMBER_OF_LAGUAGE) {
			overnum[num_ovn] = base[i];
			num_ovn++;
		}
	}
	printf("###################################\n");
	printf("overweigh:\n");
	print_passengers(&overweight[0], num_ovw);

	printf("###################################\n");
	printf("overnum:\n");
	print_passengers(&overnum[0], num_ovn);

	qsort(&overweight[0], num_ovw, sizeof(passenger), &comp);
	qsort(&overnum[0], num_ovn, sizeof(passenger), &comp);

	printf("###################################\n");
	printf("overweigh after sort:\n");
	print_passengers(&overweight[0], num_ovw);

	printf("###################################\n");
	printf("overnum after sort:\n");
	print_passengers(&overnum[0], num_ovn);


	return 0;
}

//main//main//main//main//main//main//main//main//main//main//


//funcs//funcs//funcs//funcs//funcs//funcs//funcs//funcs//funcs//

void clear_input_buffer() {
	char c;
	do {
		c = getchar();
	}
	while (c != '\n' && c != (char)4);
}

void input_num_p(int *num_p) {
	// if we don't have arr of passengers
	printf("type num of passangers: ");
	while (scanf("%d", num_p) != 1) {
		while (getchar() != '\n');
		puts("ERROR by typing num of data!\n");
		printf("type num of passangers: ");
	}
	while (getchar() != '\n');
}

void input(passenger *arr, int n) {
	
	for (int i = 0; i < n; i++) {
		printf("type surname of passenger(%d/%d): ", i+1, n);
		scanf("%s", &arr[i].surname);
		
		printf("type laguage weight of passenger(%d/%d): ", i+1, n);
		scanf("%d", &arr[i].laguage_weight);

		printf("type number of laguage of passenger(%d/%d): ", i+1, n);
		scanf("%d", &arr[i].num_of_laguage);

		if (arr[i].laguage_weight > MAX_LAGUAGE_WEIGHT) {
			arr[i].add_payment = (arr[i].laguage_weight - MAX_LAGUAGE_WEIGHT) * OVERWEIGHT_PRICE;
		}
		else {
			arr[i].add_payment = 0;
		}

		printf("additional payment of passenger(%d/%d) = %d\n\n", i+1, n,
				arr[i].add_payment);
	}
	while (getchar() != '\n');
}

void print_passenger(passenger p) {
	/*
	printf("|           surname | %s", p.surname);
	for (int i = 0; i < 64; i++) {
		printf("%d ", (int)p.surname[i]);
	}
	putchar('\n');
	*/
	printf("|           surname | %s\n", p.surname);
	printf("|    laguage weight | %d\n", p.laguage_weight);
	printf("| number of laguage | %d\n", p.num_of_laguage);
       	printf("|       add payment | %d\n", p.add_payment);
}

void print_passengers(passenger *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("| passenger(%d/%d)\n", i+1, n);
		print_passenger(arr[i]);
		putchar('\n');
	}
}

int comp(const void * A, const void *B) {
	const char *srnA = (*(const passenger *)A).surname;
	const char *srnB = (*(const passenger *)B).surname;
	return strcmp(srnA, srnB);
}

//funcs//funcs//funcs//funcs//funcs//funcs//funcs//funcs//funcs//
