#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
	unsigned int num;
	struct node* next;
}node;

node* table_a[10003];
node* table_b[10003];

int get_hash(int temp) {
	return temp % 10003;
}
int insert_hash_a(int temp) {
	int hash = get_hash(temp);
	node* new = (node*)malloc(sizeof(node));
	new->num = temp;
	new->next = table_a[hash];
	table_a[hash] = new;
}

int search_hash_a(int temp) {
	int hash = get_hash(temp);
	node* find = table_a[hash];
	while (find != NULL) {
		if (find->num == temp) {
			return 1;
		}
		find = find->next;
	}
	return 0;
}

int insert_hash_b(int temp) {
	int hash = get_hash(temp);
	node* new = (node*)malloc(sizeof(node));
	new->num = temp;
	new->next = table_b[hash];
	table_b[hash] = new;
}

int search_hash_b(int temp) {
	int hash = get_hash(temp);
	node* find = table_b[hash];
	while (!find == NULL) {
		if (find->num == temp) {
			return 1;
		}
		find = find->next;
	}
	return 0;
}

int main() {
	int a, b; scanf("%d %d", &a, &b);
	int temp;
	int* lista = (int*)malloc(sizeof(int) * a);
	int* listb = (int*)malloc(sizeof(int) * b);

	for (int i = 0; i < a; i++) {
		scanf("%d", &temp);
		lista[i] = temp;
		insert_hash_a(temp);
	}
	for (int i = 0; i < b; i++) {
		scanf("%d", &temp);
		listb[i] = temp;
		insert_hash_b(temp);
	}

	int cnt= a + b;
	for (int i = 0; i < a; i++) {
		cnt -= search_hash_b(lista[i]);
	}
	for (int i = 0; i < b; i++) {
		cnt -= search_hash_a(listb[i]);
	}
	printf("%d", cnt);
}