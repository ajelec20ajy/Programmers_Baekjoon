#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    int x[100][100] = { 0 }; 
    int n;
    scanf("%d", &n);
    int xc, yc;
    int cnt = 0;
    int** y= (int**)malloc(sizeof(int*) * n);
    for (int i = 0; i < n; i++) {
        y[i] = (int*)malloc(sizeof(int) * 2);
    } 

 

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &y[i][0], &y[i][1]);
        xc = y[i][0]; yc = y[i][1];
        for (int j = yc; j < yc + 10; j++) {
            for (int k = xc; k < xc + 10; k++) {
                if (x[j][k] == 0) { x[j][k] = 1; cnt++;}
                else continue;
            }
        }
    }
    printf("%d", cnt);


    return 0;
}