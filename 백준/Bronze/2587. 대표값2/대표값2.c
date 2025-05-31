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
	int arr[5], sum = 0;
	
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	divide(arr, 0, 5 - 1);

	printf("%d\n%d", sum / 5, arr[2]);

	return 0;
}