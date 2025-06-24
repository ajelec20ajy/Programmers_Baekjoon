#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return num1 - num2;
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return 1;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
}

int main() {
    int N;scanf("%d", &N);
    int* card = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", card+i);
    }

    int M; scanf("%d", &M);
    int* check = (int*)malloc(sizeof(int) * M);
    for (int i = 0; i < M; i++) {
        scanf("%d", check + i);
    }

    qsort(card, N, sizeof(int), compare);

    for (int i = 0; i < M; i++) {
        printf("%d ", binary_search(card, N, check[i]));
    }
   

    return 0;
}
