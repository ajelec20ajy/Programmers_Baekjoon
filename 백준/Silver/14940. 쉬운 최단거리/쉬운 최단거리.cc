#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 미쳐버리겠꾼
    // bfs 써야할듯
    // 근데 그래프 안쓰고 그냥 구현으로도 할 수 있을거같은데..
    // 일단 배열에 넣어두고, 사방면으로 검사하면서 1이면 노드 추가하고 연결해주면 될듯.
    int dy[] = { -1, 1, 0, 0 };
    int dx[] = { 0, 0, -1, 1 };

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 2) { 
                q.push({ i, j });
                dist[i][j] = 0;
            }
            else if (grid[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m) {
                if (grid[ny][nx] == 1 && dist[ny][nx] == -1) {
                    dist[ny][nx] = dist[y][x] + 1;
                    q.push({ ny, nx });
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}