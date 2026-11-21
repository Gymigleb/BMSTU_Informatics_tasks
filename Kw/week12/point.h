#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y;
} point;

point* alloc_points(size_t *n) {
	printf("type num of points: ");
	if (scanf("%zu", n) != 1) {
		exit(1);
	}

	point *p = (point*)calloc(*(n), sizeof(point));
	if (p == NULL) {
		exit(2);
	}
	return p;
}

point* realloc_points(point *p, size_t *n) {
	printf("type num of additional point: ");
	size_t a = 0u;
	if (scanf("%zu", &a) != 1) exit (5);

	size_t na = *(n) + a;
	point *pa = (point*)realloc(p, na * sizeof(point));
	if (pa == NULL) {
		free(p);
		exit(6);
	}
	*(n) = na;
	return pa;
}

void type_points(point *p, size_t i, size_t n) {
	for (; i < n; ++i) {
		printf("type cords of point %zu/%zu:\n", i+1, n);
		printf(".x = ");
		if (scanf("%f", &p[i].x) != 1) {exit(3);}
		printf(".y = ");
		if (scanf("%f", &p[i].y) != 1) {exit(4);}
		
	}
}

#endif // POINT_H
