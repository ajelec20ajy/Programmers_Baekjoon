#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    /*
    Q : LIMIT 시간 이내에 모든 퍼즐을 해결할 수 있는, 숙련도 LEVEL의 최솟값.
    -> 이진 탐색으로 찾을 수 있음.
    
    [1] level : 0 ~ 100000이면 될듯.
    [2] 그럼, 50000부터 Binary Search 시작하면 되지.
    
    [3] 제한시간 내에 모든 퍼즐을 풀 수 있는지 확인하는 로직
    while(퍼즐 개수){
        난이도 검사
        -> 풀 수 있는 퍼즐인 경우
        - time_cur 소모 // time_sum+=time_cur;
        -> 풀 수 없는 퍼즐인 경우
        - (diff-level)*(time_cur + time_prev) + time_cur 소모
        
    }
    
    */
    int left = 1;
    int right = 0;
    int level = 0;
    for(int i = 0; i < diffs.size(); i++){
        if(right < diffs[i]) right = diffs[i];
    }
    // if 가능 -> level 절반 줄여서 다시 반복
    // if 불가능 -> level * 2해서 다시 반복
    while(left<right){
        level = left + (right - left) / 2;
        long long time_sum = 0;
        for(int i = 0; i<diffs.size(); i++){
            if(diffs[i] <= level) time_sum+=times[i];
            else if(diffs[i] > level) {
                if(i == 0){
                    time_sum += ((diffs[i] - level)*times[i] + times[i]);
                }
                else{
                    time_sum += ((diffs[i]-level)*(times[i]+times[i-1]) + times[i]);
                }
            }
        }
        if(time_sum <= limit) right = level;
        else {
            left = level + 1;
        }
    }
    
    return left;
}