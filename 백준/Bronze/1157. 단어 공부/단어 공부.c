#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[1000001];

int main() {

    gets(s);

    int alphabet[26] = { 0 };
    int max = 0;
    int multimax;
    int result = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char ch = s[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + 'A' - 'a';
        }
        alphabet[ch - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        if (max < alphabet[i]) {
            multimax = 0;  max = alphabet[i]; result = 'A' + i;
        }
        else if (max == alphabet[i] && max != 0) multimax = 1;
    }

    if (multimax) printf("?"); else printf("%c", result);


    return 0;
}