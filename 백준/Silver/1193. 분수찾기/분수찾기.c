#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	int x; scanf("%d", &x);
	if (x == 1) {
		printf("1/1"); return 0;
	}
	int s=1, m=1; // s/m
	int flag = 0; // flag == 1 이면 case3, flagg == 0이면 case4
	
	for (int i = 0; i < x-1; i++) {
		if (s == 1 && flag == 0) {// x축 끝을 만났을때 case 1
			m++; flag = 1;
		}
		else if (m == 1 && flag == 1) {// y축 끝을 만났을때 case 2
			s++; flag = 0;
		}
		else if (flag == 1) { //좌하향 case3
			s++; m--;
		}
		else if (flag == 0) { //우상향 case4
			s--; m++;
		} 
	}
	
	printf("%d/%d", s, m);
	return 0;
}