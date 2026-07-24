#include <bits/stdc++.h>
using namespace std;

int count = 0;

int bfs(int start, vector<vector<int>> &graph){
    queue<int> q;
    vector<int> visited(graph.size(), 0);
    
    q.push(start);
    visited[start] = 1;
    
    int count = 0;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        count++;
        
        for(int next : graph[cur]){
            if(visited[next]) continue;
            
            visited[next] = 1;
            q.push(next);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    // wires에서 하나씩 제거해보자. 그리고 [a,b]를 제거했다면, a에서 탐색 돌려서 카운팅들어가고 나머지 쪽은 n-카운트개수겠지?
    queue<int> q;
    vector<int> visited;
    vector<vector<int>> my = wires;
    int len = wires.size();
    int getsoo = len+1;
    int min = getsoo;
for (int cut = 0; cut < wires.size(); cut++) {
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < wires.size(); i++) {
        if (i == cut) continue;  // 이 간선만 끊기

        int a = wires[i][0];
        int b = wires[i][1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int count = bfs(wires[cut][0], graph);
    if(abs(count - (getsoo-count)) < min) min = abs(count - (getsoo-count));
}
    
    return min;
}