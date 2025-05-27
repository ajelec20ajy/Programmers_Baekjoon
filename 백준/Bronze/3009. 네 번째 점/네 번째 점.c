#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int point[3][2];
	int x, y;

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &point[i][0], &point[i][1]);
	}

	if (point[0][0] == point[1][0])
		printf("%d ", point[2][0]);
	else if (point[0][0] == point[2][0])
		printf("%d ", point[1][0]);
	else if (point[1][0] == point[2][0])
		printf("%d ", point[0][0]);

	if (point[0][1] == point[1][1])
		printf("%d", point[2][1]);
	else if (point[0][1] == point[2][1])
		printf("%d", point[1][1]);
	else if (point[1][1] == point[2][1])
		printf("%d", point[0][1]);

	return 0;
}