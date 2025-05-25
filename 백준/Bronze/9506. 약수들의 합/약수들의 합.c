#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	int n = 1, sum = 0, cntf = 0, cnts = 0;
	
	while (1) {
		scanf("%d", &n); if (n == -1) break;
		printf("%d ", n);

		for (int i = 1; i < n; i++) {
			if (n % i == 0) { sum += i; cntf++; }

		}

		if (sum == n) { 
			for (int i = 1; i < n; i++) {
				if (n % i == 0) {
					sum += i; cnts++;
					if (i == 1) {
						printf("= ");
					}
					else {
						printf("+ ");
					}
					printf("%d ", i);
					if (cnts == cntf) printf("\n");
				}
			}
		}
		else {
			printf("is NOT perfect.\n");
		}
		sum = 0; cnts = 0; cntf = 0;
	}

	return 0;
}