#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int N; scanf("%d", &N);
	long long int* coord = (long long int*)malloc(sizeof(long long int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &coord[i]);
	}

	long long int* distance = (long long int*)malloc(sizeof(long long int) * (N - 1));
	for (int i = 0; i < N - 1; i++) {
		distance[i] = coord[i + 1] - coord[i];
	}

	long long int min, a, b;
	a = distance[0];
	for (int i = 1; i < N - 1; i++) {
		b = distance[i];
		while (b) {
			min = b;
			b = a % b;
			a = min;
		}
	}
	int cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		while (distance[i] != min) {
			distance[i] -= min;
			cnt++;
		}
	}

	printf("%d", cnt);

}