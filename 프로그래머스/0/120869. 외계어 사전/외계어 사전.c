#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// spell_len은 배열 spell의 길이입니다.
// dic_len은 배열 dic의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    
    for(int i = 0; i<dic_len; i++){
        int len = strlen(dic[i]);
        int cnt = 0;
        for(int j = 0; j<spell_len; j++){
            for(int k = 0; k<len; k++){
                if(spell[j][0] == dic[i][k]) {cnt++; k = len;}
            }
        }
        if(cnt == spell_len) return 1;
    }
    
    return 2;
}

/*
 dic[0]~dic[dic_len-1] 돌면서.. 만약 dic[0]차례일 때, dic[0][0] = char find, find == spell[0]~[spell_len-1] check
*/