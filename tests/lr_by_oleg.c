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
    int K,M,X=0,Z=0;
    printf("Vvedite K \n");
    scanf("%d", &K);
    printf("Vvedite M \n");
    scanf("%d", &M);
    printf("\n");
    char ZS[18][25], SZ[18*25];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            ZS[i][j] = randchar();
            printf("%2c      ", ZS[i][j]);
            SZ[X]=ZS[i][j];
            X++;
        }
        putchar('\n');
    }
    putchar('\n');
    for(int x=0; x<X;x++){
        printf("%c      ",SZ[x]);
    }
    putchar('\n');
    printf("\n");
    int n = M*K;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (SZ[j] > SZ[j + 1]) {
                int tmp = SZ[j];
                SZ[j] = SZ[j + 1];
                SZ[j + 1] = tmp;
            }
        }
    }
    putchar('\n');
    for (int i = 0; i < n; i++) {
        printf("%c      ", SZ[i]);
    }
    putchar('\n');
    printf("\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            ZS[i][j] = SZ[Z];
            printf("%2c      ", ZS[i][j]);
            Z++;
        }
        putchar('\n');
    }
    printf("\n");
    printf(" ");
    for (int i = 0; i < K; i++) {
        int has_vowel = 0;
        for (int j = 0; j < M; j++) {
            if (isvowel(ZS[j][i])) {has_vowel++;}
        }
        if (has_vowel) {printf("%d       ", has_vowel);}
        else {printf("0       ");}
    }
    return 0;
}
