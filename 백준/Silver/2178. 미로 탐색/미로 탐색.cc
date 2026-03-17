#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 미로는 걍 내인생이 미로다
    // 1은 이동가능 0은 이동 불가. (1,1)에서 출발해 (N, M)의 위치로 이동할 때 지나야하는 최소 칸의 수
    // 항상, 이동가능함이 보장됩니다.
    // 최단거리는 뭐다 BFS다

    int N, M;
    cin >> N >> M;

    vector<vector<int>> x(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            x[i][j] = (tmp[j] - '0');
        }
    }

    // 자 저는 이걸로 BFS 할거에용
    // 일단 상하좌우로 가봐야겠지요?
    
    queue<pair <int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<int>> ans(N, vector<int>(M, 0));
    
    q.push({ 0, 0 });
    visited[0][0] = true;
    ans[0][0] = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        int cur_x = cur.second;
        int cur_y = cur.first;
        
        q.pop();


        if (cur_x == N - 1 && cur_y == M - 1) {
            break; // N,M에 도달
        }
        for (int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M || !x[next_y][next_x]) continue;
            if (!visited[next_y][next_x]) {
                q.push({ next_y, next_x });
                visited[next_y][next_x] = true;
                ans[next_y][next_x] = ans[cur_y][cur_x] + 1;
            }     
        }
    }

    cout << ans[N-1][M-1];

    return 0;
}