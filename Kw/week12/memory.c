#include "point.h"

int main() {
	/*printf("type num of points: ");
	size_t n = 0u;
	if(scanf("%zu", &n) != 1) {
		return 2;
	}

	// get some memory for one element
	// point *p = malloc(sizeof(point));
	// point *p = (point)malloc(sizeof(point));
	// you cen do like that if you want to show that ot is point
	
	// get some memory for n elements
	point *p = calloc(n, sizeof(point));
	*/

	// get some data by our fync
	size_t n = 0u;
	point *p = alloc_points(&n);

	// get points
	type_points(p, 0u, n);
	
	// get additional memory
	size_t na = n;
	p = realloc_points(p, &na);
	type_points(p, n, na);	

	// clear memory
	free(p);
	p = NULL;
	return 0;
}
