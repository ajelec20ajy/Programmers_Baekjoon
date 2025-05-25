#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int N;
	scanf("%d", &N);
	int i = 2;

	while (1) {
		if(N%i == 0){
			printf("%d\n", i);
			N = N / i;
		}

		else{
			i++;
		}

		if (N == 1) break;
	}

	return 0;
}