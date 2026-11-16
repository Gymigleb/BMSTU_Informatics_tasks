#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
	float x, y;
} point;

int printf_point( point p) {
	return printf("(%.2f;%.2f)", p.x, p.y);
}

bool scanf_point(point *p) {
	printf(".x = ");
	if (scanf("%f", &((*p).x)) != 1) {
		puts("error by inserting x");
		return false;
	}
	
	printf(".y = ");
	if (scanf("%f", &((*p).y)) != 1) {
		puts("error by inserting y");
		return false;
	}
	return true;
}

float distance_between_points(const point *a, const point *b) {
	float dx = b->x - a->x, dy = a->y - b->y;
	return sqrtf(dx * dx + dy * dy);
}

float path_length(point path[], size_t n) {
	float length = 0.f;
	for(size_t i = 1u; i < n; i++) {
		length += distance_between_points(
			&path[i-1], &path[i]
		);
	}
	return length;
}

int main() {
	size_t n = 0u;
	
	printf("type num of path points: ");
	if (!scanf("%zu", &n)) {
		puts("error by inserting point num of path points");
		return 1;
	}
	
	point path[n];

	for (size_t i = 0; i < n; i++) {
		printf("type cord of point(%zu):\n", i + 1);
		if (!scanf_point(&path[i])) {
			printf("error by inserting point(%zu)", i + 1);
			return 1;
		}
	}
	
	printf("path is:\n");
	for (size_t i = 0; i < n; i++) {
		printf_point(path[i]);
	}

	putchar('\n');
	printf("length of path: %.2f\n", path_length(path, n));

	return 0;
}
