#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int x, y, z;
	scanf("%d", &x); scanf("%d", &y); scanf("%d", &z);

	if (x + y + z != 180) printf("Error");
	else if (x == 60 && x == y) printf("Equilateral");
	else if ((x == y) || (y == z) || (z == x)) printf("Isosceles");
	else printf("Scalene");

	return 0;
}