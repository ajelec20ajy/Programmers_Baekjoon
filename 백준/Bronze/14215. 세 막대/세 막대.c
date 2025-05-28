#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int m(int a, int b) {
	return a >= b ? a : b;
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (m(a, m(b, c)) < a + b + c - m(a, m(b, c))) {
		printf("%d", a + b + c);
	}

	else
		printf("%d", 2 * (a + b + c - m(a, m(b, c))) - 1);

	return 0;
}