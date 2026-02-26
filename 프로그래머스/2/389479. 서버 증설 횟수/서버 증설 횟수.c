#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// players_len은 배열 players의 길이입니다.
int solution(int players[], size_t players_len, int m, int k) {
    int* server_open = (int*)malloc(sizeof(int) * players_len); // 시간별 열은 서버
    if (server_open == NULL) {
        return -1;
    }
    memset(server_open, 0, sizeof(int) * players_len);
    int cnt = 0; // 열려있는 서버
    int open_cnt = 0; // 서버 증설 횟수
    for(int i = 0; i < players_len; i++){
        // 닫을 서버 닫기
        if(i >= k){
            cnt -= server_open[i-k]; // server_open을 0으로 초기화해놓음. 지금 시간 기준, k시간 전 열은 서버 다 닫음.
        }
        
        int people = players[i];
        // 서버 열기
        while(people >= (cnt +1) * m){ // 수용 인원 다 채울 수 있을 때 까지 증설
            server_open[i]++;
            cnt++;
            open_cnt++;
        }
    }
    
    return open_cnt++;
}