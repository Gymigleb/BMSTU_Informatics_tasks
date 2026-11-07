#include <stdio.h>
//#include <string.h>

int main() {
	char s[64];
	puts("insert string");
	//fgets(s, 65, stdin);
	scanf("%s", s);
	printf("s = \"%s\"\n", s);
	// gets(s); not working
	printf("s = \"%s\"\n", s);
	return 0;
}
