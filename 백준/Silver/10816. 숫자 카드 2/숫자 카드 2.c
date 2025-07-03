#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	long num;
	int cnt;
	struct node* next;
}node;

node* table[100007];

int get_hash(long temp) {
	return temp % 100007;
}


void insert_hash(long temp, int flag) {
	int hash = get_hash(temp);
	node* new = (node*)malloc(sizeof(node));
	if (search_hash(temp, flag)) {
		node* new = table[hash];
		while (new != NULL) {
			if (temp == new->num) {
				new->cnt++;
			}
			new = new->next;
		}
	}
	else {
		new->num = temp;
		new->next = table[hash];
		new->cnt = 1;
		table[hash] = new;
	}
}


int search_hash(long temp, int flag) {
	int hash = get_hash(temp);
	node* cur = table[hash];
	while (cur != NULL) {
		if (temp == cur->num) {
			if (flag == 0) {
				printf("%d ", cur->cnt);
			}
			return 1;
		}
		cur = cur->next;
	}
	if (flag == 0) {
		printf("0 ");
	}
	return 0;
}


int main() {

	int N, M; scanf("%d", &N); getchar();
	long temp; int flag=1;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		insert_hash(temp, flag);
	}

	scanf("%d", &M);
	long* arrM = (long*)malloc(sizeof(long) * M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &arrM[i]);
	}
	flag = 0;
	for (int i = 0; i < M; i++) {
		search_hash(arrM[i], flag);
	}
	return 0;
}