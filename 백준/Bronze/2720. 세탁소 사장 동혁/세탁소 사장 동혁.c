#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define q 25
#define d 10
#define n 5
#define p 1

int main() {

	int T; scanf("%d", &T); 
	int **out = (int**)malloc(sizeof(int*) * T);
	for (int i = 0; i < T; i++) {
		out[i] = (int*)malloc(sizeof(int) * 4);
	}

	int* price = (int*)malloc(sizeof(int) * T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &price[i]);
	}

	for (int i = 0; i < T; i++) {
		if (price[i] == 0) {
			out[i][0] = 0; out[i][1] = 0; out[i][2] = 0; out[i][3] = 0;
		}
		int remain = price[i];
		int j = 0;
		while (remain) {
			for (j = 0; remain >= q; j++) {
				remain -= q;
			}
			out[i][0] = j;
			for (j = 0; remain >= d; j++) {
				remain -= d;
			}
			out[i][1] = j;
			for (j = 0; remain >= n; j++) {
				remain -= n;
			}
			out[i][2] = j;
			for (j = 0; remain >= p; j++) {
				remain -= p;
			}
			out[i][3] = j;
		}
	}

	for (int i = 0; i < T; i++) {
		printf("%d %d %d %d\n", out[i][0], out[i][1], out[i][2], out[i][3]);
	}
	return 0;
}