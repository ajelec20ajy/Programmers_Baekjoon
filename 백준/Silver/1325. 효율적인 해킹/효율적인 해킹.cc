#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // A가 B를 신뢰 한다 -> 입력 = A B -> B를 해킹하면 A도 해킹되는 것과 같음. 유향인듯. 그러면, B->A로 보는게 맞겠다.
    // 그냥 무향 그래프 만들고, 젤 간선 많은 노드 고르면 대겠구만
    // 아 아니다..... 쭉 파고들어야되는구나 ㅠ
    // 일단 근데 모든 컴퓨터가 연결되어있는건 보장된거겠지..?
    int N, M;
    cin >> N >> M;

    using Graph = vector<vector<int>>;
    Graph G(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        G[b].push_back(a);
    }

    // dfs
    
    vector<int> ans(N+1, 0);
    vector<int> visited(N + 1, 0);
    int visit_id = 0;
    for (int i = 1; i <= N; i++) { 
        stack<int> s;
        s.push(i);
        visit_id++;
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            if (visited[cur] == visit_id) continue;

            visited[cur] = visit_id;
            ans[i]++;
            for (int n : G[cur]) {
                if (visited[n] != visit_id) {
                    s.push(n);
                }
            }
        }
    }

    int max = 0;
    for (int n : ans) {
        if (n >= max) max = n;
    }

    for (int i = 1; i <= N; i++) {
        if (ans[i] == max) {
            cout << i << " ";
        }
    }

    return 0;
}