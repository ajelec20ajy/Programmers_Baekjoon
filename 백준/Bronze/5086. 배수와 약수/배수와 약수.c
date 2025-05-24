#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

	int n, m;

	while (1) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0) {
			break;
		}
		else {
			if (n % m == 0 && n > m) {
				printf("multiple\n");
			}

			else if (m % n == 0 && n < m) {
				printf("factor\n");
			}
			else {
				printf("neither\n");
			}
		}
	}

	return 0;
}