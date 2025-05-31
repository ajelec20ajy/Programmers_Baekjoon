#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char xxx[3] = "666";
	char arr[20];
	int cnt = 0;

	int N; scanf("%d", &N);

	for (int i = 666; i < 22231666; i++) {
		sprintf(arr, "%d", i);
		if (strstr(arr, "666")) {
			cnt++;
		}
		if (cnt == N) {
			printf("%s", arr);
			return 0;
		}
	}

}