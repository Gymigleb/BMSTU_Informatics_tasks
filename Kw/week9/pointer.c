#include <stdio.h>

int main() {
	char c[] = {'A', 'B'};
	printf("c[0] = '%c'; c[1] = '%c'\n", c[0], c[1]);
	char *pC = &c[0];
	printf("pC = %p\n", pC);
	*pC = 'B';
	printf("c[0] = '%c'; c[1] = '%c'\n", c[0], c[1]);
	pC = pC + 1;
	*pC = 'C';
	printf("c[0] = '%c'; c[1] = '%c'\n", c[0], c[1]);
	return 0;
}
