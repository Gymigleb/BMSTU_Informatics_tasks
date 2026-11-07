#include <stdio.h>
#include <string.h>

int main() {
	puts("type string of words: ");
	char words[32][64], word[64], c;
	int m = 0;
	do {
		scanf("%s%c", words[m], &c);
		m++;
	} while (c != 10);
	puts("your words:");
	for (int i = 0; i < m; i++) {
		printf("%2d: %15s (%2d)\n", i + 1, words[i], strlen(words[i]));
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (strcmp(words[i], words[j]) < 0) {
				strcpy(word, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], word);
			}
		}
	}
	puts("your words after sorting:");
	for (int i = 0; i < m; i++) {
		printf("%2d: %15s (%2d)\n", i + 1, words[i], strlen(words[i]));
	}

	char str[256] = "";
	for (int i = 0; i < m; i++) {
		strcat(str, words[i]);
		strcat(str, " ");
	}
	puts("new str:");
	puts(str);
	return 0;
}
