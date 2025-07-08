#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int numa, dea, numb, deb;
	int numx, dex;
	scanf("%d %d", &numa, &dea); scanf("%d %d", &numb, &deb);

	dex = dea * deb;
	numx = deb * numa + dea * numb;

	int a = numx, b = dex, temp;
	
	while (b) {
		temp = b;
		b = a % b;
		a = temp;
	}

	printf("%d %d", numx/a, dex/a);

}


