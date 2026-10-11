#include <stdio.h>
#include <math.h>

double Y(double x) {return x * exp(-pow(x, 2)) / (1 + x);}

int main()
{
	// const double e = exp(1);
	double x, y1, y2;

	printf("type x: ");
	scanf("%lf", &x);
	
	// calculatin y1 with additional varibles
	double E, S1, S2, S, up, down;
	E = exp(-pow(x, 2));
	S1 = 1 - 2 * pow(x, 2);
	S2 = 1 + x;
	S = S1 * S2 - x;
	up = E * S;
	down = pow(1 + x, 2);
	y1 = up / down;
	
	// calculatin y2 without additional varibles
	y2 = exp(-pow(x, 2)) * ((1 - 2 * pow(x, 2)) * (1 + x) - x) / pow(1 + x, 2);

	printf("derivative  with   additional varibles y1(x) = %10.4e\n", y1);
	printf("derivative without additional varibles y2(x) = %10.4e\n", y2);

	int cnt = 0;
	double dx  = 0.2, dy, d, a;
	
	// printf("   a         dy        d       y1       dx\n");
	//       1     10         11           12
	printf("+-+----------+-----------+------------+------------+\n");
	printf("|N|increments|approximate|  absslute  |     dx     |\n");
	printf("| | of func  |  values   |   errors   |            |\n");
	printf("+-+----------+-----------+------------+------------+\n");
	while (cnt < 8)
	{
		dy = Y(x + dx) - Y(x);
		d = dy / dx;
		a = fabs(d - y1);
		
		printf("|%d|%10.3e|%11.4e|%12.5e|%11.10lf|\n", cnt+1, dy, d, a, dx);
		// printf("%lf %lf %lf %lf %.10lf\n", a, dy, d, y1, dx);
		dx = dx * 0.2;
		cnt++;
	}
	printf("+-+----------+-----------+------------+------------+\n");

	return 0;
}
