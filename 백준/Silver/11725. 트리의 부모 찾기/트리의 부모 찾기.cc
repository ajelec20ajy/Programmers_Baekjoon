#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left_child;
    Node* right_child;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 트리 루트가 1일때, 각 노드의 부모를 구하는 프로그램
    // 2번 노드부터 출력

    int N;
    cin >> N;

    using Tree = vector<vector<int>>;
    Tree T(N + 1);

    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;

        T[a].push_back(b);
        T[b].push_back(a);
    }

    // BFS로 해볼까
    queue<int> q;
    vector<int> visited(N + 1, false);
    vector<int> parent(N + 1);
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;

        for (int next : T[cur]) {
            if (!visited[next]) {
                q.push(next);
                parent[next] = cur;
            }
        }
    }

    for (int n : parent) {
        if(n)
        cout << n << "\n";
    }

    return 0;
}