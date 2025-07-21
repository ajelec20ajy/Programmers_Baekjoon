#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
	int num[100001];
	int top;
}Stack;


void init(Stack* s) {
	s->top = -1;
}

void push(Stack* s, int num){
	s->num[++(s->top)] = num;
}

int pop(Stack* s) {
	if (s->top == -1) return -1;
	else {
		return s->num[s->top--];
	}
}

int main() {
	int k; scanf("%d", &k);

	Stack s;
	init(&s);
	int temp;

	for (int i = 0; i < k; i++) {
		scanf("%d", &temp);
		if (temp) {
			push(&s, temp);
		}
		else {
			pop(&s);
		}

	}

	long long sum = 0;
	for (int i = 0; i <= s.top; i++) {
		sum = sum + s.num[i];
	}

	printf("%lld", sum);

	

	return 0;
}