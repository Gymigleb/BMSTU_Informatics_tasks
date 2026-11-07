#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h> // bool, true, false

char randchar() {
	char c = 0;
	do {
		c = rand() % 128;
	}
	while (!isalpha(c));
	return c;
}

bool isvowel(char c) {
	switch (c) {
		case 'A':
		case 'E':
		case 'I':
		case 'U':	
		case 'O':
		case 'Y':
		case 'a':
		case 'e':
		case 'i':
		case 'u':
		case 'o':
		case 'y': return true;
		default: return false;
	}
}

int main () {
	srand(time(NULL));
	puts("table of random simbols:");
	char c = 0;
	for (int i = 0; i < 5; i++) {
		int has_vowel = 0;
		for (int j = 0; j < 5; j++) {
			c = randchar();
			printf("%2c", c);
			if (isvowel(c)) {has_vowel++;}
		}
		if (has_vowel) {printf(" num of vowels in str: %d", has_vowel);}
		else {printf(" no vowels ;(");}
		putchar('\n');
	}
	return 0;
}
