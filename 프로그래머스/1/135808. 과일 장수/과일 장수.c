#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int *)b - *(int *)a);
}
// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int boxcnt = score_len / m;
    int **box = (int**)malloc(sizeof(int*)*boxcnt);
    for(int i = 0; i<boxcnt; i++){
        box[i] = (int*)malloc(sizeof(int)*m);
    }
    qsort(score, score_len, sizeof(int), compare);
    
    for(int i = 0; i<boxcnt; i++){
        for(int j = i*m, a =0; a<m; a++,j++){
            box[i][a] = score[j];
        }
    }
    int answer = 0;
    for(int i = 0; i<boxcnt; i++){
        int min = k;
        for(int j = 0; j<m; j++){
            if(box[i][j] < min) min = box[i][j];
        }
        answer+=(min*m);
    }
    
    return answer;
}
/* 상자 내 사과의구성은 같아야 함. 
음 일단은, 가격 = (box내 최저점수) * (m) * (상자개수) 
점수별로 카운팅할까?
score_len C 1 부터 score_len C m 까지 다 해보는게 답인가?

*/