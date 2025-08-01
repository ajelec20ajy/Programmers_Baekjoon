#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int top;
}stack;
void init(stack *s){
    s->top = -1;
}


void push(stack* s) {
    s->top = s->top + 1;
}

int pop(stack* s) {
    if (s->top == -1) return -1;
    else {
        s->top = s->top - 1;return 1;
    }
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    stack st; init(&st);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') { push(&st);}
        else if (s[i] == ')') { if(pop(&st) == -1) return false; }
    }
    if (st.top != -1) { return false; }
    else return true;
}