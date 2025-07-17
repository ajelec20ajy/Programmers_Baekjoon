#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int num[1000001] = { 0, };

int check_prime(const int temp) {

	for (int i = 2; i * i <= temp; i++) {
		for (int j = i; j * i <= temp; j++) {
			num[i * j] = 1;
		}
	}

}

int get_gp(const int temp) {
	int cnt = 0;

	for (int i = 2; i <= temp/2; i++) {
		int j = temp - i;
		if (num[i] == 0 && num[j] == 0) {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int T;
	scanf("%d", &T);
	int temp;
	int tempmax = 0;
	num[0] = 1;
	num[1] = 1;
	while (T--) {
		scanf("%d", &temp);
		if (temp > tempmax) {
			tempmax = temp;
			check_prime(tempmax);
		}
		printf("%d\n",get_gp(temp));
	}
	return 0;
}