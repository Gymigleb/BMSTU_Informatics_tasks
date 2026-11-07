#include <stdio.h>

int main() {
	int n;
	
	printf("type num of numbers in array: ");
	scanf("%d", &n);
	
	int arr[n];

	for (int i = 0; i < n; i++) {
		printf("type %d element: ", i + 1);
		scanf("%d", &arr[i]);
	}

	int iMin = 0, iMax = 0, p[n], s[n];
	
	p[n-1] = arr[n-1];
	s[0] = arr[0];
	for (int i = 1; i < n; i++) {
		p[n-1-i] = p[n-i] * arr[n-1-i];
		s[i] = s[i-1] + arr[i];
		if (arr[i] < arr[iMin]) {iMin = i;}
		if (arr[i] > arr[iMax]) {iMax = i;}
	}
	printf("your arr: ");
	for (int i = 0; i < n; i++) {printf("%d ", arr[i]);}
	putchar('\n');
	printf("arr of sum: ");
	for (int i = 0; i < n; i++) {printf("%d ", s[i]);}
	putchar('\n');
	printf("arr of proizv: ");
	for (int i = 0; i < n; i++) {printf("%d ", p[i]);}
	putchar('\n');
	printf( "iMax = %d; iMin = %d; arr[iMax] = %d; arr[iMin] = %d;\n"
		"sum = %d; proizv = %d", iMax, iMin, arr[iMax], arr[iMin], s[n-1], p[0]);
	if (iMin == 0) {arr[iMin] = 0;}
	else {arr[iMin] = s[iMin - 1];}
	if (iMax == n-1) {arr[iMax] = 0;}
	else {arr[iMax] = p[iMax + 1];}
	
	printf("\nredacted arr: ");
	for (int i = 0; i < n; i++) {printf("%d ", arr[i]);}
	putchar('\n');

}
