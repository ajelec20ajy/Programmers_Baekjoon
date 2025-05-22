#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	long long int n = 1;
	long long int in;
	scanf("%lld", &in);
	for (int i = 0; i < 100000; i++) { // in >= n && in <= n+(6*i=1) 
		if (n == 1) {
			if (in == 1) {
				printf("1"); return 0;
			}
			else {
				n++;
			}
		}
		else {
			if (in >= n && in < n + i * 6) {
				printf("%d", i+1); return 0;
			}
			else {
				n = n + 6 * i;
			}
		}
	}

	return 0;
}