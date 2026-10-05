#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int> > maps) // maps는 [y][x]
{
    // 그런거라면 와타시는 stack을 쓰겠습니다.
    
    queue<pair<int,int>> q; // first=x, second=y;
    vector<vector<int>> visited(maps.size(), vector<int>(maps[0].size(), 0));
    
    q.push({0,0});
    
    int target_x = maps[0].size() - 1;
    int target_y = maps.size() - 1;
    
    while(!q.empty()){
        pair<int,int> now = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];
            
            // 1. 범위검사
            if(next_x < 0 || next_x >= maps[0].size() || next_y < 0 || next_y >= maps.size()) continue;
            // 2. visited 검사
            if(visited[next_y][next_x]) continue;
            // 3. 벽 검사
            if(maps[next_y][next_x] == 0) continue;
            
            q.push({next_x, next_y});
            visited[next_y][next_x] = visited[now.second][now.first]+1;
        }
    }
    
    
    int ans = visited[target_y][target_x];
    return ans == 0 ? -1 : ans+1;
}