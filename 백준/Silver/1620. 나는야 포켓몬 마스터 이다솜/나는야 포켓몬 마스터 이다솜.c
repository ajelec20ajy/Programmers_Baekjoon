#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	char name[21];
	int index;
	struct node* next;
}node;

node* table[10007];

int get_hash(char* temp) {
	int c;
	unsigned long hash = 5381;
	while (c = *temp++) {
		hash = hash * 33 + c;
	}
	return hash % 10007;
}


void insert_hash(char* temp, int i) {
	int hash = get_hash(temp);
	node* new = (node*)malloc(sizeof(node));
	new->index = i;
	strcpy(new->name, temp);
	new->next = table[hash];
	table[hash] = new;
}


int search_hash(char* temp) {
	int hash = get_hash(temp);
	node* cur = table[hash];
	while (cur != NULL) {
		if (strcmp(cur->name, temp) == 0) {
			printf("%d\n", cur->index);
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}


int main() {
	int n, m; scanf("%d %d", &n, &m); getchar();
	int num_test;
	char temp[21];
	char** table_num = (char**)malloc(sizeof(char*) * n);
	char** for_m = (char**)malloc(sizeof(char*) * m);
	for (int i = 0; i < n; i++) {
		table_num[i] = (char*)malloc(sizeof(char) * 21);
	}
	for (int i = 0; i < m; i++) {
		for_m[i] = (char*)malloc(sizeof(char) * 21);
	}

	//입력단
	for (int i = 0; i < n; i++) {
		gets(temp);
		insert_hash(temp, i + 1);
		strcpy(table_num[i], temp);
	}

	int num = 0;

	//출력단
	for (int i = 0; i < m; i++) {
		gets(temp);
		strcpy(for_m[i], temp);
	}
	for (int i = 0; i < m; i++) {
		num = 0;
		if (isdigit(for_m[i][0])) {
			int num = atoi(for_m[i]);
			printf("%s\n", table_num[num - 1]);
		}
		else {
			search_hash(for_m[i]);
		}
	}
	return 0;
}