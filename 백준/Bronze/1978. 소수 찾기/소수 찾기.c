#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int N;
	scanf("%d", &N);
	int* num = (int*)malloc(sizeof(int) * (N));
	int cnt = 0;
	int out = 0;
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= num[i]; j++) {
			if (num[i] % j == 0) { cnt++; }
		}
		if (cnt == 2){ out++;}
		cnt = 0;
	}

	printf("%d", out);

	return 0;
}