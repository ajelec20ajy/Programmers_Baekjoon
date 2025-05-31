#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int left, int mid, int right) {
	int temp[1000];
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}


	//끝났는데 기존 배열에 left나 right 배열에 남은게 있는 경우
	while (i <= mid) { temp[k++] = arr[i++];}
	while (j <= right) { temp[k++] = arr[j++];}

	for (int a = 0; a < k; a++) {
		arr[left + a] = temp[a];
	}

};

int divide(int arr[], int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	// left로 나누기
	divide(arr, left, mid);
	// right으로 나누기
	divide(arr, mid + 1, right);
	merge(arr, left, mid, right);
};

int main() {
	int N; scanf("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	divide(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}

/*
병합 정렬 
[1] 분할 : 리스트를 반 쪼갠다. 각 1개씩 남을때 까지 쭉 쪼갠다.
[2] 정복 : 나누어진 부분 배열을 정렬한다
[3] 결합 : 정렬된 부분 배열을 합병한다.
*/