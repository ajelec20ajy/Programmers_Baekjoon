#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

bool isPrime(int num) {
    if (num < 2) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

void dfs(vector<int>& nums, vector<bool>& visited, int start, int level, int n){
    if(level == n){
        // 도달
        int sum = 0;
        for(int i = 0; i < visited.size(); i++){
            if(visited[i]) sum+=nums[i];
        }
        if(isPrime(sum)) cnt++;
        return;
    }
    
    for(int i = start; i < visited.size(); i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(nums, visited, i+1, level+1, n);
        visited[i] = false;
    }
}

int solution(vector<int> nums) {
    vector<bool> visited(nums.size(), false);
    int level = 0;
    int n = 3;
    dfs(nums, visited, 0, level, n);
    
    return cnt;
}