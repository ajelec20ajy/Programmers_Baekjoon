#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void swap(int score[], int left, int right) {
	int temp;
	temp = score[left];
	score[left] = score[right];
	score[right] = temp;
}

void quicksort(int score[], int start, int end) {
	if (start >= end) return;
	int pivot = score[(start + end) / 2];
	int i = start; int j = end;
	while (i <= j) {
		if (score[i] >= pivot && score[j] <= pivot) {
			swap(score, i, j); i++; j--;
		}
		else if (score[i] < pivot) {
			i++;
		}
		else if (score[j] > pivot) {
			j--;
		}
		
	}
	quicksort(score, start, j);
	quicksort(score, i , end);
}

int main() {
	int N, k; scanf("%d %d", &N, &k);
	int* score = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &score[i]);
	}
	
	quicksort(score, 0, N - 1);

	printf("%d", score[N-k]);

	return 0;
}