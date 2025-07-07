#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
	struct Node* child[26];
	int end;
}Node;


struct Node* create() {
	Node* node = (Node*)malloc(sizeof(Node));
	node->end = 0;
	for (int i = 0; i < 26; i++) {
		node->child[i] = NULL;
	}
	return node;
}

void insert(Node* root, char* key) {
	Node* pCrawl = root;
	for (int i = 0; i < strlen(key); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->child[index]) {
			pCrawl->child[index] = create();
		}
		pCrawl = pCrawl->child[index];
	}
	pCrawl->end = 1;
}

int search(Node* root, char* key) {
	Node* temp = root;
	for (int i = 0; i < strlen(key); i++) {
		int index = key[i] - 'a';
		if (!temp->child[index]) {
			return 0;
		}
		temp = temp->child[index];
	}
	return temp->end;
}

int compare(void* a, void* b) {
	return strcmp(*(char**)a, *(char**)b);
}

int main() {
	int N, M; scanf("%d %d", &N, &M); getchar();
	Node* root = create();

	for (int i = 0; i < N; i++) {
		char temp[21];
		gets(temp);
		insert(root, temp);
	}


	char** mlist = (char**)malloc(sizeof(char*) * M);
	char name_search[21]; int cnt = 0;
	for (int i = 0; i < M; i++) {
		gets(name_search);
		if (search(root, name_search)) {
			mlist[cnt] = (char*)malloc(sizeof(char) * 21);
			strcpy(mlist[cnt], name_search);
			cnt++;
		}
	}

	qsort(mlist, cnt, sizeof(char*), compare);

	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%s\n", mlist[i]);
	}


}