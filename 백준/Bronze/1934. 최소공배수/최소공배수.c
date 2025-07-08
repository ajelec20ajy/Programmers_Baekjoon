#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int T; scanf("%d", &T);
	int a, b, temp;
	int* answ = (int*)malloc(sizeof(int) * T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &a, &b); 
		for (int j = 1; j <= b; j++) {
			if ((a * j) % b == 0) {
				answ[i] = (a * j);
				break;
			}
		}
		
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", answ[i]);
	}
}


