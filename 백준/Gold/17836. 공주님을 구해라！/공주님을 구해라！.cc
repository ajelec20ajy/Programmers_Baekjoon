#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0 , 1, -1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 일단 동일하게 상하좌우 이동하는데, 벽이 있는 곳으로는 못감
    // 근데 만약에, 그람을 획득하면 그런거 없이 다 이동할 수 있음
    // 그러면, 결국은 그람없이 가기 vs 그람 먹은 경우네
    // 어떻게 구분할까? 일단 오징어제육볶음을 먹고 풀어보자
    // 자 다먹었다
    // 근데, 그람을 먹은 패스가 그냥 가는 패스보다 길 수도 있는거자나
    // 아니 그것보다 문제는. gram을 먹은 경로와 다른 경로를 구분해야대.

    int N, M, T;
    cin >> N >> M >> T;

    vector<vector<int>> grid(N+1, vector<int> (M+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int tmp;
            cin >> tmp;
            grid[i][j] = tmp;
        }
    }
    typedef struct state{
        int x, y, gram;
    }state;
    queue<state> q;
    vector<vector<vector<int>>> time(
        N + 1,
        vector<vector<int>>(M + 1, vector<int>(2, 1e9))
    );
    // [x][y][0] : gram 없을떄, [x][y][1] : 그람있을때
    time[1][1][0] = 0; 
    q.push({ 1, 1, 0});

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int ng = cur.gram;

            if (nx < 1 || nx > M || ny < 1 || ny > N) continue;

            if (grid[ny][nx] == 2) ng = 1;

            if (!ng && grid[ny][nx] == 1) continue;

            if (time[ny][nx][ng] > time[cur.y][cur.x][cur.gram] + 1) {
                time[ny][nx][ng] = time[cur.y][cur.x][cur.gram] + 1;
                q.push({ nx,ny,ng });
            }
        } 
    }
    int min = time[N][M][0] >= time[N][M][1] ? time[N][M][1] : time[N][M][0];
    if (min > T) cout << "Fail";
    else cout << min;

    return 0;
}