#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    vector<int> my = citations;
    int ans = 0;
    int len = citations.size();
    // 조건 1: h번 이상 인용된 논문의 '개수'가 h편 이상일 것 -> 결국 h는 len 이하네
    for(int h = 0; h <= 10000; h++){
        int cnt = 0; // h번 이상 인용된 논문의 개수
        int cnt2 = 0; // 그 이외의 논문
        for(int j = 0; j < len; j++){
            if(h <= my[j]){
                cnt++;
            }
            else{
                cnt2++;
            }
        }
        if(cnt >= h){
            if(ans < h) ans = h;
        }
    }
    return ans;
}