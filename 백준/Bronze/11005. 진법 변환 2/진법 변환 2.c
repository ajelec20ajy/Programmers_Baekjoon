#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

	long long int N, ref;
	int B;
	scanf("%lld %d", &N, &B);
	char out[31];
	ref = N;


		for (int i = 0; i < 31; i++) {
			if (B > ref) { // LSB 도달 조건
				if(ref < 10 && ref >= 0) {
					out[i] = ref + '0';
				}	
				else if (ref >= 10 && ref <= 36) {
					out[i] = ref + 55;
				}
				out[i + 1] = '\0';
				break;
			}
			else { // 진행중...
				if (ref % B >= 10 && ref % B <= 36) { //알파벳이 필요할 때
					out[i] = (ref % B) + 55;
				}
				else if (ref % B < 10 && ref % B >= 0) { //0~9의 숫자로 잇츠오케이일때
					out[i] = (ref % B) + '0';
				}
				ref = ref / B;
			}
		}


		int len = strlen(out);
		for (int i = len - 1; i >= 0; i--) {
			printf("%c", out[i]);
		}
}