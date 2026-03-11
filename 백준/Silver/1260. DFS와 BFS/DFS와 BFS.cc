#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    using Graph = vector<vector<int>>;
    Graph G(N + 1);

    for (int i = 1; i <= M; i++) { // 그래프 만들기
        int a, b;
        cin >> a >> b;
        G[a].push_back(b); // G[1] : 1 노드에 연결된 애들.
        G[b].push_back(a);
    }
    /*
    for (int i = 1; i <= N; i++) { // 그래프 확인차 출력
        cout << i << "번째 : ";
        for (int a : G[i]) {
            cout << a << " ";
        }
        cout << "\n";
    }
    */
    // 작은 것 먼저 방문 원칙을 위한 오름차순 정렬
    for (int i = 1; i <= N; i++) {
        sort(G[i].begin(), G[i].end());
    }

    // DFS : 인접 노드 중 작은 숫자들 먼저 밑으로 쭈주주죽 탐색하는것의 반복
    stack<int> s;
    vector<bool> visited_dfs(N + 1, false);
    s.push(V);
    while (!s.empty()) {
        int cur = s.top(); // 지금 탑이 뭐야 = 지금 어느 노드에 있는거야?
        s.pop(); // 지금 탑 방문합니다.
        if (visited_dfs[cur]) continue; // 어라 이미 방문했네? 그럼 그냥 넘어가서 이전 스택탑의 그 밑에걸로 갑니다

        visited_dfs[cur] = true; // 방문 처리
        cout << cur << " "; // 방문했습니다~
        
        for (int i = G[cur].size() - 1; i >= 0; i--) {
            int next = G[cur][i]; // 자 다음에 방문해야하는 곳은 여기야
            if (!visited_dfs[next]) { // 처음이면, push해서 방문예정으로 만들고, 이미 방문했던곳이면 패스
                s.push(next); // 다음에 여기 가렴
            }
        }
    }

    cout << "\n";

    // BFS : 인접 노드에 전부 방문
    queue<int> q;
    vector<bool> visited_bfs(N + 1, false);
    q.push(V);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (visited_bfs[cur]) continue;
        visited_bfs[cur] = true;
        cout << cur << " "; // 방문했습니다~
        
        for (int next : G[cur]) {
            if (!visited_bfs[next]) {
                q.push(next);
            }
        }
    }

    return 0;
}