#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	int N, K, cnt = 0, i = 1;
	scanf("%d %d", &N, &K);
	while (1) {
		if (N % i == 0) {
			cnt++;
			if (cnt == K) {
				printf("%d", i); break;
			}
		}
		if (N == i && cnt < K) {
			printf("0"); break;
		}
		i++;
	}

	return 0;
}