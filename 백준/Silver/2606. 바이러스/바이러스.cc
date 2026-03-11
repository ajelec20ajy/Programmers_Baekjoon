#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    queue<int> q;
    
    int N, M;
    cin >> N >> M;
    vector<bool> visited(N + 1, false);
    using Graph = vector<vector<int>>;
    Graph G(N+1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        sort(G[i].begin(), G[i].end());
    }

    q.push(1);
    int cnt = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
 
        if (visited[cur]) continue; 
        cnt++;
        visited[cur] = true;

        for (int n : G[cur]) {
            if (visited[n]) continue;
            else q.push(n);
        }
    }
    cout << cnt-1;
    return 0;
}