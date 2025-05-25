#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int start, end;
	scanf("%d", &start);
	scanf("%d", &end);
	int min, sum = 0, cnt = 0;

	for (int i = start; i <= end; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) cnt++;
		}
		if (cnt == 2) {
			if (sum == 0) { min = i; }
			sum += i; 
		}
		cnt = 0;
	}

	if (sum == 0) printf("-1");
	else printf("%d\n%d", sum, min);

	return 0;
}