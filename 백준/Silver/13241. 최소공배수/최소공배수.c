#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	long long int a, b, answ;
	scanf("%lld %lld", &a, &b);
	for (long long int j = 1; j <= b; j++) {
		if ((a * j) % b == 0) {
			answ = (a * j);
			break;
		}
	}
		

	printf("%lld\n", answ);
}


