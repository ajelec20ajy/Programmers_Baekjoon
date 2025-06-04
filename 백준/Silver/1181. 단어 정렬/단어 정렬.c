#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char s[201];
	int len;
} word;


void merge(word* words, int left, int mid, int right) {
	word* temp = (word*)malloc(sizeof(word) * (right - left + 1));
	int i = left;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= right) {
		if (words[i].len > words[j].len) {
			temp[k++] = words[j++];
		}
		else if (words[i].len < words[j].len) {
			temp[k++] = words[i++];
		}
		else {
			if (strcmp(words[i].s, words[j].s) < 0) { //앞에거가 작으면 strcmp는 음수, 앞에거가 크면 양수반환
				temp[k++] = words[i++];
			}
			else if (strcmp(words[i].s, words[j].s) > 0) {
				temp[k++] = words[j++];
			}
			else {
				temp[k++] = words[i++]; temp[k++] = words[j++];
			}
		}
	}

	while (i <= mid) { temp[k++] = words[i++]; }
	while (j <= right){ temp[k++] = words[j++];}

	for (int a = 0; a < k; a++) {
		words[left + a] = temp[a];
	}

}


void divide(word* words, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) / 2;

	divide(words, left, mid);
	divide(words, mid + 1, right);
	merge(words, left, mid, right);
}


int main() {

	int N; scanf("%d", &N); getchar();



	word* words = (word*)malloc(sizeof(word) * N);
	for (int i = 0; i < N; i++) {
		fgets(words[i].s, 201, stdin);
		words[i].s[strcspn(words[i].s, "\n")] = '\0'; 
		words[i].len = strlen(words[i].s);
	}

	divide(words, 0, N - 1);

	printf("%s\n", words[0].s);
	for (int i = 1; i < N; i++) {
		if (strcmp(words[i].s, words[i - 1].s) != 0)
			printf("%s\n", words[i].s);
	}


	return 0;
}