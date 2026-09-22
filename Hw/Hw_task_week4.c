#include <stdio.h>
#include <math.h>

int main() {
	float x, y;
	printf("type x = ");
	scanf("%f", &x);
	x = fabs(x);
	if (x <= 1.0) {y = x - 1;}
	else if (x < 2) {y = -x + 1;}
	else {y = -1;}
	printf("y = %f", y);
	return 0;
}
