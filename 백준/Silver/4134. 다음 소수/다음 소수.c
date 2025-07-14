#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef long long l;

int is_prime(l num) {
	if (num < 2) return 0;
	for (l i = 2; i*i <= num; i++) {
		if (num % i == 0) return 0;
	}
	return 1; // 소수다
}

int main() {
	int testcase; scanf("%d", &testcase);
	l* num = (l*)malloc(sizeof(l) * testcase);
	for (int i = 0; i < testcase; i++) {
		scanf("%lld", &num[i]);
	}

	int flag;
	for (int i = 0; i < testcase; i++) {
		while (1) {
			flag = is_prime(num[i]);
			if (flag == 0) { num[i] += 1; }
			else break;
			
		}
		printf("%lld\n", num[i]);
	}
}