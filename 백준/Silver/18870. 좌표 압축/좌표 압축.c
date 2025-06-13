#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    return (num1 > num2) - (num1 < num2);
}

int binary_search(int* arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int N;
    scanf("%d", &N);


    int* origin = (int*)malloc(sizeof(int) * N);
    int* sorted = (int*)malloc(sizeof(int) * N);
    int* unique = (int*)malloc(sizeof(int) * N); 

    for (int i = 0; i < N; i++) {
        scanf("%d", &origin[i]);
        sorted[i] = origin[i];
    }

    qsort(sorted, N, sizeof(int), cmp);

    int unique_size = 0;
    unique[unique_size++] = sorted[0];
    for (int i = 1; i < N; i++) {
        if (sorted[i] != sorted[i - 1]) {
            unique[unique_size++] = sorted[i];
        }
    }

    for (int i = 0; i < N; i++) {
        int compressed = binary_search(unique, unique_size, origin[i]);
        printf("%d ", compressed);
    }

    return 0;
}