#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
	int N; scanf("%d", &N);

	int num;
	int arr[10000] = { 0 };

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		arr[num-1]++;
	}

	for(int i = 1; i<=10000;i++){
			while (arr[i - 1]>0) {
				printf("%d\n", i);
				arr[i - 1]--;
			}
	}


	return 0;
}
