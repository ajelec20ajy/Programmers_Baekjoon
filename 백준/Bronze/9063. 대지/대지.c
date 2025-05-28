#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	
	int x, y, xmax=-1e+4, xmin=1e+4, ymax=-1e+4, ymin=1e+4;
	int n; scanf("%d", &n);

	while (n--) {
		scanf("%d %d", &x, &y);
		xmax = (xmax <= x ? x : xmax);
		xmin = (xmin >= x ? x : xmin);
		ymax = (ymax <= y ? y : ymax);
		ymin = (ymin >= y ? y : ymin);
	}

	printf("%d", (xmax - xmin) * (ymax - ymin));

	return 0;
}