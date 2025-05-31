#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int N; scanf("%d", &N);
	int test = 0;
	int min = N / 3;

	int th = N / 3; int fi = N / 5;

	for (int i = 0; i <= fi; i++) {
		for (int j = 0; j <= th; j++) {
			if (((i * 5) + (j * 3)) == N) {
				test = 1;
				if ((i + j) < min) min = (i + j);
			}
		}
	}
	
	if (test == 0) printf("-1");
	else printf("%d", min);
	return 0;
}