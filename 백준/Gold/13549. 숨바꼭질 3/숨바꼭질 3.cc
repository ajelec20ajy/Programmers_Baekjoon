#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 수빈이가 X에서 1초마다 -1, +1하거나, 순간이동으로 0초 걸려서 2*X의 위치로 이동함
    // 수빈이는 현재 N, 동생은 K에 있음.

    // 1차원 그래프
    // BFS를 써야겠군

    int N, K;

    cin >> N >> K;

    queue<int> q;
    vector<int> time(100001, 1e9);
    q.push(N);
    time[N] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == K) break;

        if (cur < 100000) { if (time[cur + 1] > time[cur] + 1) { q.push(cur + 1);  time[cur + 1] = time[cur] + 1; } }
        if (cur > 0) { if (time[cur - 1] > time[cur] + 1) { q.push(cur - 1); time[cur - 1] = time[cur] + 1; } }
        if (cur * 2 <= 100000 && time[cur * 2] > time[cur]) { q.push(cur * 2);  time[cur * 2] = time[cur]; } // Y(=X*2)를 도달하던 기존 방법보다, X에서 순간이동한게 더 빠르면
        
    }

    cout << time[K];

    return 0;
}