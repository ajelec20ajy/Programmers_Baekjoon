#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	int a1, a0, c, n0;
	scanf("%d %d", &a1, &a0);
	scanf("%d", &c);
	scanf("%d", &n0);

	printf("%d", (a1 * n0 + a0 <= c * n0) && (c >= a1));

	return 0;
}