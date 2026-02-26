#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#define INF 255
// info_rows는 2차원 배열 info의 행 길이, info_cols는 2차원 배열 info의 열 길이입니다.
int solution(int** info, size_t info_rows, size_t info_cols, int n, int m) {
uint8_t dp[m];
    uint8_t next_dp[m];
    // 초기화
    for(int i = 0; i < m; i++) dp[i] = INF;
    dp[0] = 0;
    
    for(size_t i = 0; i < info_rows; i++){
        uint8_t a = (uint8_t)info[i][0];
        uint8_t b = (uint8_t)info[i][1];
        
        for(int k = 0; k < m; k++) next_dp[k] = INF;
        
        for(int j = 0; j < m; j++){
            if(dp[j] == INF) continue;
            
            // A가 가져가는 경우 (B 흔적 유지)
            if(next_dp[j] > dp[j] + a) {
                next_dp[j] = dp[j] + a;
            }
            
            // B가 가져가는 경우 (B 흔적 증가)
            if(j + b < m) {
                if(next_dp[j + b] > dp[j]) {
                    next_dp[j + b] = dp[j];
                }
            }
        }
        // 계산 결과를 현재 dp로 복사
        memcpy(dp, next_dp, sizeof(uint8_t) * m);
    }
    
    uint8_t ans = INF;
    for(int i = 0; i < m; i++){
        if(dp[i] < n && dp[i] < ans){
            ans = dp[i];
        }
    }
    
    return (ans == INF) ? -1 : (int)ans;
}