#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 수빈양은 X 위치에서, 1초후 X-1 또는 X+1로 이동가능하고, 순간이동을 한다면 1초 후 2*X의 위치로 이동한다.
    // 동생쿤이 K에 있을 때, 수빈양이 동생을 가장 빨리 잡을 수 있는 시간!

    int N, K;
    cin >> N >> K;

    // 1차원 bfs라..

    queue<int> q;
    vector<bool> visited(100001, false);
    vector<int> ans(1000001, 0);

    q.push(N);
    visited[N] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == K) break;
            if (!visited[cur - 1] && cur >= 1 && cur <= 100000) {
                    q.push(cur - 1);
                    ans[cur - 1] = ans[cur] + 1;
                    visited[cur - 1] = true;
            }
            if (!visited[cur + 1] && cur <= 99999 && cur >= 0) {    
                    ans[cur + 1] = ans[cur] + 1;
                    q.push(cur + 1);
                    visited[cur + 1] = true;
            }
            if (!visited[cur * 2] && cur <= 50000 && 2*cur >= 0) {  
                    q.push(cur * 2);
                    ans[cur * 2] = ans[cur] + 1;
                    visited[cur * 2] = true;          
            }

    }

    cout << ans[K];

    return 0;
}