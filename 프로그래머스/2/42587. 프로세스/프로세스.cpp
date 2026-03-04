#include <string>
#include <vector>
#include <queue>
#include <stdint.h>
using namespace std;

struct info{
    int p, i;
};

int solution(vector<int> priorities, int location) {
    queue<info> q;
    priority_queue<int> pq;
    uint8_t len = priorities.size();
    uint8_t max = 0;
    uint8_t index = 0;

    for(uint8_t i = 0; i < len; i++){
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    uint8_t flag = 1;
    uint8_t cnt = 0;
    // pq 다 뽑을때까지
    while(flag){
        uint8_t target = pq.top(); // 이번에 뽑을 태스크 = 타겟
        cnt++;
        do{
            if(q.front().p == target) {
                if(q.front().i == location){
                    flag = 0;
                }
                else{
                    pq.pop(); // 이번거 끝!
                    q.pop();
                }
                break;
            }
            else{           
                q.push(q.front()); // 아닌거니깐 맨뒤로가세요
                q.pop();
            }
        }while(1);
    }
    
    uint8_t answer = cnt;
    return answer;
}