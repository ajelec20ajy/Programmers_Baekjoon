#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int m(int a, int b);

int main() {
	int x, y, z;
	while (1) {
		scanf("%d\n%d\%d", &x, &y, &z);
		if (x == 0 && y == 0 && z == 0) return 0;
		else {
			if (m(z, m(x, y)) >= (x + y + z - m(z, m(x, y)))) {
				printf("Invalid\n");
			}
			else if (x == y && x == z) {
				printf("Equilateral\n");
			}
			else if (x == y || x == z || y == z) {
				printf("Isosceles\n");
			}
			else printf("Scalene\n");
		}
	}
	return 0;
}

int m(int a, int b) {
	return a >= b ? a : b;
}