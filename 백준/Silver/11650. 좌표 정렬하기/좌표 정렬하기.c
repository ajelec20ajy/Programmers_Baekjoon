#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int **cord, int left, int right) {
	int* temp;
	temp = cord[left];
	cord[left] = cord[right];
	cord[right] = temp;
}

void quick(int **cord, int left, int right, int c) {
	if (left >= right) return;
	int i = left, j = right;
	int pivot = cord[(left + right) / 2][c];
	while (i <= j) {
		while (cord[i][c] < pivot) i++;
		while (cord[j][c] > pivot) j--;
		if (i <= j) {
			swap(cord, i, j);
			i++; j--;
		}
	}

	quick(cord, left, j, c);
	quick(cord, i, right, c);
}

int main() {
	int N; scanf("%d", &N);
	int** cord = (int**)malloc(sizeof(int**) * N);
	for (int i = 0; i < N; i++) {
		cord[i] = (int*)malloc(sizeof(int) * 2);
		scanf("%d %d", &cord[i][0], &cord[i][1]); // x좌표 at 0, y좌표 at 1
	}
	
	quick(cord, 0, N - 1, 0); // cord, start, end, x에대한 정렬 = 0 || y에 대한 정렬 = 1

	int start = 0;
	for (int i = 1; i <= N; i++) {
		if (i == N || cord[i][0] != cord[start][0]) {
			if (i - start > 1) {
				quick(cord, start, i - 1, 1);  // y좌표 정렬
			}
			start = i;
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", cord[i][0], cord[i][1]);
	}

	return 0;
}
