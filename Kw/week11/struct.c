#include <stdio.h>

struct point {
	float x, y;
};

int printf_point(struct point p) {
	return printf("(%.2f;%.2f)", p.x, p.y);
}

int main() {
	printf("sizeof(struct point) = %zu\n", sizeof(struct point));
	printf("sizeod(float) = %zu\n", sizeof(float));
	struct point a, b = {5.f, 6.f}, c = {.x = 7.f, .y = 8.f};
	a.x = 3.f;
	a.y = 3.f;
	printf("a = "); printf_point(a); putchar('\n');
	printf("b = "); printf_point(b); putchar('\n');
	printf("c = "); printf_point(c); putchar('\n');
	return 0;
}
