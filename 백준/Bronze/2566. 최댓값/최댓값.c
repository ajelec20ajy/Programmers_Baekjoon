#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int num[9][9];
    int max = 0;
    int low, col;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (max < num[i][j]) {
                max = num[i][j];
                low = i;
                col = j;
            }
            else if (max == num[i][j]) {
                low = i; col = j;
            }
        }
    }

    printf("%d\n%d %d", max, low+1, col+1);

    return 0;
}