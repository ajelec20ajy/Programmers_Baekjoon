#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
int solution(int n) {
    int end = sqrt(n);
    int cnt = 0;
    int* arr = (int*)malloc(sizeof(int) * n); // 0~n-1이 각각 1~n임. 체크되면;합성수면 1이다.
    for (int i = 0; i < n; i++) arr[i] = 0;
    for (int i = 2; i <= end; i++) {
        for (int j = 2; i * j <= n; j++) {
            if (arr[i * j - 1] == 0) { arr[i * j - 1] = 1; cnt++; printf("%d\n", i * j); }

    }
}
    return cnt;
}