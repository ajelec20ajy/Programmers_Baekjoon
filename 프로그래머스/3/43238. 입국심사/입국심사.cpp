#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long left = 1;
    long long right = times[0];
    for(int i = 0; i < times.size(); i++){
        if(right < times[i]) right = times[i];
    }
    right = right * n;
    
    while(left < right){
        long long mid = left + (right-left) / 2;
        // 조건 판단 - mid 타임안에 심사를 받을 수 있느냐
        // times[k] 심사관은 mid 시간 안에, mid/times[k]명의 사람을 쳐낼 수 있음.
        long long human_cnt = 0;
        for(int i = 0; i < times.size(); i++){
            human_cnt += mid/times[i]; // 쳐낼 수 있는 사람의 수
        }
        if(human_cnt >= n) right = mid;
        else left = mid + 1;
    }
    
    return left;
}