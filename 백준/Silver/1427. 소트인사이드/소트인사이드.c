#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);

	int len = 1, temp = N;
	while ((temp /= 10) != 0) len++;

	int* num = (int*)malloc(sizeof(int) * len);

	temp = N;
	for (int i = len - 1; i >= 0; i--) {
		num[i] = temp % 10;
		temp /= 10;
	}


	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < len; j++) {
			if (i == num[j]) printf("%d", i);
		}
	}
	

	return 0;
}