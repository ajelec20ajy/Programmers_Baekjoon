#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char case1[8][8] = { "BWBWBWBW" , "WBWBWBWB" , "BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" };
	char case2[8][8] = { "WBWBWBWB", "BWBWBWBW" , "WBWBWBWB" , "BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW", "WBWBWBWB" ,"BWBWBWBW" };
	int N, M; scanf("%d %d", &N, &M); getchar();
	int min = 64;
	int cnt1 = 0, cnt2 = 0,cnt = 0;
	
	char **arr = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		arr[i] = (char*)malloc(sizeof(char) * (M + 1)); 
		gets(arr[i]);
	}

	for (int x = 0; x <= N - 8; x++) {
		for (int y = 0; y <= M - 8; y++) {
			for (int i = 0; i <= 7; i++) {
				for (int j = 0; j <= 7; j++) {
					if (arr[x+i][y+j] != case1[i][j]) cnt1++;
					if (arr[x+i][y+j] != case2[i][j]) cnt2++;
				}
			}
			cnt = cnt1 <= cnt2 ? cnt1 : cnt2;
			if (cnt < min) min = cnt;
			cnt1 = 0; cnt2 = 0;
		}
	}
	
	printf("%d", min);

	return 0;
}