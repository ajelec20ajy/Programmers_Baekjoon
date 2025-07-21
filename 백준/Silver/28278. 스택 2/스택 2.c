#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
	int data[1000001];
	int top;
}stack;
stack s;
void init(stack* s) {
	s->top = -1;
}
short is_empty(stack* s) {
	if (s->top == -1) return 1;
	else return 0;
}

void push(stack* s, int X) {
	s->data[++(s->top)] = X;
}

int pop(stack* s) {
	if (is_empty(s)) return -1;
	else {
		int x = s->data[s->top];
		s->top--;
		return x;
	}
}

int main() {
	int N; scanf("%d", &N);
	 init(&s);
	
	while (N--) {
		int inst; int X;
		scanf("%d", &inst);
		switch (inst) {
		case 1: {
			scanf("%d", &X);
			push(&s, X);
			break;
		}
		case 2: {
			printf("%d\n", pop(&s));
			break;
		}
		case 3: {
			printf("%d\n", s.top+1);
			break;
		}
		case 4: {
			printf("%d\n", is_empty(&s));
			break;
		}
		case 5: {
			if (is_empty(&s)) {
				printf("-1\n");
			}
			else {
				printf("%d\n", s.data[s.top]);
			}
			break;
		}
		}
	}
	return 0;
}