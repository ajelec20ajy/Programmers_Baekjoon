#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int getlen(long long int N, int len) {
	if (N / 10 == 0) { return ++len; }
	else {
		N = N / 10;
		len++;
		getlen(N, len);
	}
};

int dec(int i) { // 10^i 구현
	int x = 1;
	if (i == 0) return 1;
	else {
		for (int j = 1; j <= i; j++) {
			x *= 10;
		}
		return x;
	}
};

long long int cal(long long int N, int len) { // num의 각 자릿수를 더한 값을 반환하는 함수(243 = 2+4+3 = 9
	long long int sum = 0; 
	for (int i = len; i > 0; i--) {

		sum += (N % dec(i)) / dec(i - 1);
		
	}
	return sum;
};

int main() {

	long long int N; scanf("%lld", &N);
	int len = 0;
	len = getlen(N, len);
	long long int min = N;

	for (int i = N; i > 0; i--) {
		if (min > i && i+cal(i,len) == N) {
			
			min = i;
		}
	}

	if (min == N) {
		printf("0"); return 0;
	}
	
	printf("%lld", min);

	return 0;
}