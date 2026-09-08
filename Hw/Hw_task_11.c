#include <stdio.h>
#include <math.h>

int main() {
	double a = 4.0, b = 3.0, x, y, up, down;
	while(true) {
		printf("tupe x: ");
		scanf("%lf", &x);
		up = pow(a-b, 1.0/3.0) * pow(a+b, 2.0/3.0) * pow(x, 2);
		down = pow(a, 4) + pow(b, 4) - 2*pow(a*b, 2) - pow(x, 4);
		y = pow(up / down, 1.0/x);
		printf("y = %lf\n", y);
	}
}
