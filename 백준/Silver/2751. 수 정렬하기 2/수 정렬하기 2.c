#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int merge(long long int arr[], long long int left, long long int mid, long long int right, long long int N) {
	long long int* temp = (long long int*)malloc(sizeof(long long int) * N);
	int i = left;
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}


	//끝났는데 기존 배열에 left나 right 배열에 남은게 있는 경우
	while (i <= mid) { temp[k++] = arr[i++]; }
	while (j <= right) { temp[k++] = arr[j++]; }

	for (int a = 0; a < k; a++) {
		arr[left + a] = temp[a];
	}

};

int divide(long long int arr[], long long int left, long long int right, long long int N) {
	if (left >= right) return;
	int mid = (left + right) / 2;
	// left로 나누기
	divide(arr, left, mid, mid-left+1);
	// right으로 나누기
	divide(arr, mid + 1, right, right-mid+1);
	merge(arr, left, mid, right, right-left+1);
};

int main() {
	long long int N; scanf("%lld", &N);

	long long int* num = (long long int*)malloc(sizeof(long long int) * N);

	for (long long int i = 0; i < N; i++) {
		scanf("%lld", &num[i]);
	}

	divide(num, 0, N - 1, N);

	for (int i = 0; i < N; i++) {
		printf("%lld\n", num[i]);
	}

	return 0;
}

/*
병합 정렬
[1] 분할 : 리스트를 반 쪼갠다. 각 1개씩 남을때 까지 쭉 쪼갠다.
[2] 정복 : 나누어진 부분 배열을 정렬한다
[3] 결합 : 정렬된 부분 배열을 합병한다.
*/