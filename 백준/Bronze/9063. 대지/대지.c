#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int n, xmax, xmin, ymax, ymin;
	scanf("%d", &n);

	int** c = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		c[i] = (int*)malloc(sizeof(int) * 2);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &c[i][0], &c[i][1]);
	}
	if (n < 2) {printf("0"); return 0;}
	//find max x
	xmax = c[0][0];
	for (int i = 0; i < n; i++) {
		if (xmax < c[i][0]) xmax = c[i][0];
	}
	xmin = xmax;
	//find min x
	for (int i = 0; i < n; i++) {
		if (xmin > c[i][0]) xmin = c[i][0];
	}
	//find max y
	ymax = c[0][1];
	for (int i = 0; i < n; i++) {
		if (ymax < c[i][1]) ymax = c[i][1];
	}
	ymin = ymax;
	//find min y
	for (int i = 0; i < n; i++) {
		if (ymin > c[i][1]) ymin = c[i][1];
	}

	printf("%d", (xmax - xmin) * (ymax - ymin));
	return 0;
}