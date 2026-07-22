#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    //i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
    //computer[i][i]는 항상 1입니다.
    int answer = 0; // 0인거 만나면 +1하면 되나요 잘 모르겠긴하겠심더dfs로 가다가.

    vector<int> visited(n, 0); // visited 변수
    // 방문하지 않은 점을 만났을때마다 DFS를 돌린다.
    for(int i = 0; i < n; i++){
        if(visited[i]) continue;
        answer++;
        stack<int> st;
        visited[i] = 1;
        st.push(i);
        
        while(!st.empty()){
            int cur = st.top();
            st.pop();
            
            for(int j = 0; j < n; j++){
                if(visited[j]) continue;
                if(j == cur) continue;
                if(computers[cur][j]){ // 서로 연결되어있음
                    visited[j] = true;
                    st.push(j);
                }
            }
        }
    }
        return answer;
}

/*
110
111
011
*/