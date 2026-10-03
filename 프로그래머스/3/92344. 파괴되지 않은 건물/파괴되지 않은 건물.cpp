#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    vector<vector<int>> prefix(board.size()+1, vector<int> (board[0].size()+1, 0));
    
    for(int i = 0; i < skill.size(); i++){
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        
        int tmp = (type == 2) ? degree : degree*(-1);
        
        prefix[r1][c1] += tmp;
        prefix[r1][c2+1] -= tmp;
        prefix[r2+1][c1] -= tmp;
        prefix[r2+1][c2+1] += tmp;
    }
    int prev = 0;
    for(int i = 0; i < prefix.size(); i++){
        prev = 0;
        for(int j = 0; j < prefix[0].size(); j++){
            prefix[i][j] += prev;
            prev = prefix[i][j];
        }
    }
    for (int i = 1; i < prefix.size(); i++) {
        for (int j = 0; j < prefix[0].size(); j++) {
            prefix[i][j] += prefix[i - 1][j];
    }
}
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            board[i][j] += prefix[i][j];
        }
    }
    
    int ans = 0;
    for(vector<int> x : board){
        for(int y : x){
            if(y>0) ans++;
        }
    }
    
    return ans;
}