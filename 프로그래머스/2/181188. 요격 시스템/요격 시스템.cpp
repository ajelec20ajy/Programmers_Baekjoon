#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](vector<int> a, vector<int> b){
        if(a[1] != b[1]) return a[1]<b[1];
        return a[0] < b[0];
    });
    
    int ans = 0;
    int end = 0;

    for (const auto& target : targets) {
        int s = target[0];
        int e = target[1];

        if (ans == 0 || s >= end) {
            ans++;
            end = e;  // 이 끝점 바로 직전에 요격한다고 생각
        }
    }

    return ans;
}