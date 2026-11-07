#include <stdio.h>

int main() {
	char words [64][128];
	char c;
	size_t m = 0;
	do {
		scanf("%s%c", words[m], &c);
		++m;
	} while (c != 10);
	printf("num of words is: %zu\n", m);
	return 0;
}
