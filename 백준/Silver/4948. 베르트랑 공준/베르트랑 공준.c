#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int n;

int ap() {
	scanf("%d", &n);
	if (n == 0) return 0;
	else return che(n);
}
int che(int n) {
	int x = n;
	int y = 2 * x;
	int num[246913] = { 0, };
	num[0] = num[1] = 1;
	
	for (int i = 2; i * i <= y; i++) {
		for (int j = 2; j * i <= y; j++) {
			num[i * j] = 1;
		}
	}

	int cnt = 0;
	for (int i = (x+1); i <= y; i++) {
		if (num[i] == 0) {
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 1;

}

int main() {
	int n;

	while (1) {
		if (ap() == 0) {
			break;
		}
		else continue;
	}

	return 0;
}


