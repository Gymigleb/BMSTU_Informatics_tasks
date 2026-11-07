#include <stdio.h>
#include <math.h>

int main() {
	float x1, x2, y1, y2;
	printf("type x = ");
	scanf("%f", &x1);
	x2 = x1;
	// x = fabs(x);
	// if (x <= 1.0) y1 = x - 1;
	// else if (x < 2) y1 = -x + 1;
	// else y1 = -1;
	// printf("y1 = %f\n", y1);
	
	x1 = fabs(x1);
	if (x1 < 2) y1 = -fabs(x1 - 1);
	else y1 = -1;
	printf("y1 = %f\n", y1);
	
	if (-2 < x2 && x2 < 2) y2 = -fabs(fabs(x2) - 1);
	else y2 = -1;
	printf("y2 = %f\n", y2);
	
	return 0;
}
