#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {

    char data[59];
    float score;
    int hakjum;
    float sumscore = 0;
    int sumhakjum = 0;

    for (int i = 0; i < 20; i++) {
        gets(data);
        int len = strlen(data);
        if (data[len - 1] == '+') {
            score = 69.5 - data[len - 2]; hakjum = data[len - 6] - 48;
        }
        else if (data[len - 1] == '0') {
            score = 69 - data[len - 2]; hakjum = data[len - 6] - 48;
        }
        else if (data[len - 1] == 'F') {
            hakjum = data[len - 5] -48; score = 0;
        }
        else if (data[len - 1] == 'P') {
            score = 0; hakjum = 0;
        }
        sumscore += (hakjum * score);
        sumhakjum += hakjum;
    }

    printf("%.6lf", sumscore / sumhakjum);

    return 0;
}