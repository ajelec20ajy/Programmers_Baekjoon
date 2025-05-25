#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char ch[5][16];
    int len[5];

    for (int i = 0; i < 5; i++) {
        gets(ch[i]);
    }

    for (int i = 0; i < 5; i++) {
        len[i] = strlen(ch[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = len[i]; j < 16; j++) {
            ch[i][j] = ' ';
        }
    }


    for (int j = 0; j < 15; j++) {
        for (int i = 0; i < 5; i++) {
            if (ch[i][j] != ' ') printf("%c", ch[i][j]);
       }
    }

    return 0;
}
