#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
	int M, N; 
	scanf("%d %d", &M, &N);

	int num[1000001] = { 0, }; // 1~1,000,000
	num[0] = num[1] = 1;

	for (int i = 2; i*i <= N; i++) {

			for (int j = 2; j*i <= N; j++) {
				num[i * j] = 1;
			}
		
	}

	for (int i = M; i <= N; i++) {
		if (num[i] == 0) printf("%d\n", i);
	}

	return 0;
}