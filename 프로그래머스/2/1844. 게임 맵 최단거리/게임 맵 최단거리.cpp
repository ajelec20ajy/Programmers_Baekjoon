#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > maps)
{
    //최단이니깐 bfs로 가자
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int m = maps.size(); //세로
    int n = maps[0].size(); // 가로
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int,int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    //x방향이 2차원이고 y방향이 1차원이다

    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
        if(current.first == n-1 && current.second == m-1){
            return visited[current.second][current.first];
        }
        
        for(int i = 0; i < 4; i++){
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];
            
            if((nx<0) || (nx>=n) || (ny<0) || (ny>=m)) continue;
            if(maps[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            
            visited[ny][nx] = visited[current.second][current.first]+1;
            q.push({nx, ny});
            
        }
    }
    
    return -1;
}