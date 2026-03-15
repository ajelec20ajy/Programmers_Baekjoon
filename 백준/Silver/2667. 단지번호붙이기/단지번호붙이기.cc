#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 흠 어떡하지
    // 일단 그리드에다가 0, 1 다 받아
    // 그 다음에 바로 dfs 들어가
    // 근데, 문제는 단지를 어떻게 구분하냐야
    // 그냥 visited를 추가로 넣을까? v를 넘겨가면서, visited가 아닌데 1이면 dfs 추가하는거지 어때
    // ㄱㅊ은듯? ㄱㄱ

    int N;
    cin >> N;
    vector<vector<int>> grid(N, vector<int>(N));
    

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    vector<vector<bool>> visited(N, vector<bool>(N, false)); // dfs 시작점 정할때, 이미 방문한건지 체크하려고
    vector<int> ans;
    int cnt = 0;
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 }; // 이동용
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) { // 일단 브루투포스맹키로 모든 노드 탐색해야할듯
            if (!visited[i][j] && grid[i][j]) {
                ans.push_back(1);
                int x = j, y = i;
                // dfs 시작
                stack<pair <int, int>> s;
                s.push({ y, x });
                visited[i][j] = true;
                while (!s.empty()) {
                    pair<int, int> cur = s.top();
                    s.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = dx[k] + cur.second;
                        int ny = dy[k] + cur.first;
                        if (nx >= 0 && nx < N && ny>=0 && ny < N && !visited[ny][nx] && grid[ny][nx]) {
                            s.push({ ny, nx });
                            visited[ny][nx] = true;
                            ans[cnt]++;
                        }
                    }
                }
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    sort(ans.begin(), ans.end());

    for (int n : ans) {
        cout << n << "\n";
    }

    return 0;
}