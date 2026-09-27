#include <bits/stdc++.h>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    
    bool visited[11][11][5] = {false}; // [x][y][dir] : 시작점&방향
    // [5][6][U]을 true로 했으면, [6][5][D]도 true로 해줘야함.
    pair<int,int> now = {5, 5}; // x, y
    for(char c : dirs){
        pair<int, int> tmp = now;
        pair<int,int> dir;
        int dir_inv;
        int dir_l;
        switch(c){
            case 'U' : 
                dir = {0, 1};
                dir_l = 1;
                break;
            case 'D' : 
                dir = {0, -1};
                dir_l = 2;break;
            case 'L' : 
                dir = {-1, 0};
                dir_l = 3;break;
            case 'R' : 
                dir = {1, 0};
                dir_l = 4;break;
        }
        tmp.first += dir.first; // next x
        tmp.second += dir.second; // next y
        if(tmp.first < 0 || tmp.first > 10 || tmp.second < 0 || tmp.second > 10){ // 좌표 초과
            continue;
        }
        
        switch(dir_l){
            case 1: dir_inv = 2; break;
            case 2: dir_inv = 1; break;
            case 3: dir_inv = 4; break;
            case 4: dir_inv = 3; break;
        }
        if(visited[now.first][now.second][dir_l]){ // 이미 방문
            
        }
        else if(visited[tmp.first][tmp.second][dir_inv]){// 이미 방문
        }
        else{ // 첫 방문
            answer++;
            visited[now.first][now.second][dir_l] = true;
            visited[tmp.first][tmp.second][dir_inv] = true;
            
        }
        //cout << "{X,Y,DIR_L}" << now.first << ", " << now.second << ", " << dir_l <<endl;
       //cout << "{X,Y,DIR_inv}" << tmp.first << ", " << tmp.second << ", " << dir_inv <<endl;
        now = tmp;
    }
    
    return answer;
}