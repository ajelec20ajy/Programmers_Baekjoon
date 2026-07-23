#include <bits/stdc++.h>

using namespace std;

vector<int> visited;
int ans = 0;
void dfs(int hp, int count, vector<vector<int>> &dungeons){
    ans = (ans < count) ? count : ans;
    
    for(int i = 0; i <dungeons.size(); i++){
        if(visited[i]) continue;
        if(dungeons[i][0] > hp) continue;
        visited[i] = 1;
        dfs(hp-dungeons[i][1], count+1, dungeons);
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    for(int i = 0; i<dungeons.size(); i++){
        visited.push_back(0);
    }
    
    dfs(k, 0, dungeons);
        
    return ans;
}