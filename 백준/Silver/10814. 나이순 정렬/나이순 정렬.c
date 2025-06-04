#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int age;
	char name[201];
	int index;
} M;

int comparecriterion();

int comparecriterion(const void* a, const void* b) {
	const M* x = (M*)a;
	const M* y = (M*)b;

	if (x->age != y->age) {
		return x->age - y->age; //
	}
	else {
		return x->index - y->index;
	}

}

int main() {
	
	

	int N; scanf("%d", &N);
	
	M* member = malloc(sizeof(M) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d %s", &member[i].age, member[i].name);
		member[i].index = i;
	}

	qsort(member, N, sizeof(M), comparecriterion);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", member[i].age, member[i].name);
	}

	return 0;
}