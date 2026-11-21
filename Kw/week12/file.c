#include "point.h"

int main() {
	size_t n = 0u;
	point *p = alloc_points(&n);
	type_points(p, 0u, n);
	return 0;
}
