#include <bits/stdc++.h>

using namespace std;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
int solution(vector<string> maps) {
    // 최단거리는 bfs - queue
    
    // 일단은 시작점을 찾아야겠네? 굳이 이런 노가다를 해야 된다니
    int n = maps[0].size(); //x
    int m = maps.size(); //y
    int x, y; // start
    int lx, ly; // 레버 위치
    int ex, ey; // 종료점
    int distance_to_L; // 레버까지최단시간
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(maps[i][j] == 'S'){
                x = j; y = i;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(maps[i][j] == 'L'){
                lx = j; ly = i;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(maps[i][j] == 'E'){
                ex = j; ey = i;
            }
        }
    }
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int,int>> q; // 헷갈리지마 visited랑 maps는 [y][x], pair는 x, y다.
    q.push({x, y});
    visited[y][x] = 1;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        
        q.pop();
        // 검사
        if(cx == lx && cy == ly){
            distance_to_L = visited[cy][cx] - 1;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || nx>=n || ny <0 || ny >= m) continue;
            if(maps[ny][nx] == 'X') continue;
            if(visited[ny][nx]) continue;
            
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({nx, ny});
        }
    }
    if(visited[ly][lx] == 0) return -1;
    while(!q.empty()) q.pop();
    q.push({lx, ly});
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    visited[ly][lx] = 1;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        
        q.pop();
        // 검사
        if(cx == ex && cy == ey){
            return visited[cy][cx] - 1 + distance_to_L;
        }
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || nx>=n || ny <0 || ny >= m) continue;
            if(maps[ny][nx] == 'X') continue;
            if(visited[ny][nx]) continue;
            
            visited[ny][nx] = visited[cy][cx] + 1;
            q.push({nx, ny});
        }
    }
    
    return -1;
}