#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char name[6];
	int state;
	struct node* next;
}node;

node *table[1000001];

int get_hash(char* name) {
	int c;
	unsigned long hash = 5381;
	while (c = *name++) {
		hash = hash * 33 + c;
	}
	return hash % 10007;
}

int insert_hash(char* name) {
	int hash = get_hash(name);
	node* new = (node*)malloc(sizeof(node));
	strcpy(new->name, name);
	new->next = table[hash];
	table[hash] = new;
}

void delete_hash(char* name) {
	int hash = get_hash(name);
	node* cur = table[hash];

	if (strcmp(cur->name, name) == 0) {
		table[hash] = cur->next;
		free(cur);
		return;
	}

	while (cur->next) {
		if (strcmp(cur->next->name, name) == 0) {
			node* temp = cur->next;
			cur->next = cur->next->next;
			free(temp);
			return;
		}
		cur = cur->next;
	}
}

int str(char** list, int cnt) { // list 배열에 복사
	int x = 0;
	for (int i = 0; i < 1000001; i++) {
		node* cur = table[i];
		while (cur != NULL) {
			list[x] = (char*)malloc(sizeof(char) * (strlen(cur->name) + 1));
			strcpy(list[x], cur->name);
			x++;
			cur = cur->next;
		}
	}
}

int comp(const void* a, const void* b) {
	return strcmp(*(char**)b, *(char**)a);
}

int main() {
	char name[6];
	int state;
	char st[6];
	long n;
	int cnt = 0;
	scanf("%d", &n); getchar();

	for (int i = 0; i < n; i++) {
		scanf("%s %s", name, st);
		if (strcmp(st, "enter")) {
			state = 0;
		}
		else {
			state = 1;
		}
		if (state) {
			insert_hash(name);
			cnt++;
		}
		else {
			delete_hash(name);
			cnt--;
		}
	}
	 
	char** list = (char**)malloc(sizeof(char*) * cnt); 
	str(list, cnt);

	qsort(list, cnt, sizeof(char*), comp);

	for (int i = 0; i < cnt; i++) {
		printf("%s\n", list[i]);
	}

	return 0;
}