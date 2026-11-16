#include <stdio.h>

int main() {
	int a, b;
	char c;
	for (int i = 0; i < 10; i++) {
		a = scanf("%d", &b);
		c = getchar();
		printf("a=%d, b=%d, c='%c'=%d\n", a, b, c, (int)c);
	}
}
