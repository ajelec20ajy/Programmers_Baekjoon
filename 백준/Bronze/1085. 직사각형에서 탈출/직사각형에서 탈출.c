#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	// +x방향이 가까울 때
	int px = w - x;
	// -x방향이 가까울 때
	int nx = x;
	// +y방향이 가까울 때
	int py = h - y;
	// -y방향이 가까울 때
	int ny = y;

	if (px <= nx && px <= py && px <= ny)
		printf("%d", px);
	else if (nx <= px && nx <= py && nx <= ny)
		printf("%d", nx);
	else if (py <= px && py <= nx && py <= ny)
		printf("%d", py);
	else printf("%d", ny);


	return 0;
}