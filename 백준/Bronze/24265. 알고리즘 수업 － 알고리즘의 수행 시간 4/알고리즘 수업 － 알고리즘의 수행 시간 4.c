#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	long long int n;
	scanf("%lld", &n);

	long long int count = 0;

	for (int i = 1; i < n; i++) {
		count = count + (n - i);
	}

	printf("%lld\n2", count);

	return 0;
}