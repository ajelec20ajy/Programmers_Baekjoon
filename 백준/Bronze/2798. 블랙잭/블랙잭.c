#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int* card = (int*)malloc(sizeof(int) * N);
	int sum, max = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &card[i]);
	}

	for (int i = 0; i <= N - 3; i++) {
		for (int j = i + 1; j <= N - 2; j++) {
			for (int k = j + 1; k <= N - 1; k++) {
				sum = card[i] + card[j] + card[k];
				if (sum > max && sum <= M) max = sum;
			}
		}
	}

	printf("%d", max);
	

	return 0;
}
