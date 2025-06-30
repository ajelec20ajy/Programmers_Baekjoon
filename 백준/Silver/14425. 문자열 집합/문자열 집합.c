#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char str[501];
    int check;
    struct Node* next;
}Node;

Node* table[10007];

int get_hash(char* temp) {
    unsigned long hash = 5381;
    int c;
    while ((c = *temp++)) {
        hash = hash * 33 + c;
    }
    return hash % 10007;
}

int insert_hash(char* temp) {
    int hash = get_hash(temp);
    Node* new = (Node*)malloc(sizeof(Node));
    strcpy(new->str, temp);
    new->next = table[hash];
    new->check = 0;
    table[hash] = new;
}

int search_hash(char* temp) {
    int hash = get_hash(temp);
    Node* find = table[hash];
    while (find != NULL) {
        if (strcmp(find->str, temp) == 0) {
            return 1;
        }
        find = find->next;
    }
    return 0;
    return 0;
}

int main() {
    int N, M; scanf("%d %d", &N, &M); getchar();

    char temp[501];

    for (int i = 0; i < N; i++) {
        gets(temp);
        insert_hash(temp);
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        gets(temp);
        cnt += search_hash(temp);
    }

    printf("%d", cnt);
    return 0;
}