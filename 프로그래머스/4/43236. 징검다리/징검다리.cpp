#include <bits/stdc++.h>

using namespace std;

bool possible(const vector<int>& rocks, int n, int x, int distance) {
    int last = 0;  // 처음 기준점은 출발점
    int cnt = 0;

    for (int rock : rocks) {
        if (rock - last < x) {
            cnt++;        // 현재 바위 제거
        } else {
            last = rock;  // 현재 바위 유지
        }
    }

    // 도착점까지 너무 가까우면 마지막으로 남긴 바위를 제거
    if (distance - last < x) {
        cnt++;
    }

    return cnt <= n;
}


int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    // 일단 최댓값 찾는거니깐 이분탐색을 고민해봅시다
    // possible: 바위 n개를 제거했을 때 거리 사이의 최솟값이 x가 될 수 있는가요?
    sort(rocks.begin(), rocks.end(), [] (int a, int b){return a<b;});
    int min = 0;
    int max = distance;
    int ans = 0;
    while(min <= max){
        int mid = min + (max-min)/2; // 각 지점 사이의 거리의 최솟값 후보
        
        if(possible(rocks, n, mid, distance)){
            // 가능하다면, mid를 더 키워봐
            min = mid + 1;
            ans = mid;
        }
        else{
            max = mid - 1;
        }
    }
    
    return ans;
}