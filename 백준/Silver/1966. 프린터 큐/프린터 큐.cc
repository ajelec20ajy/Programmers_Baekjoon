#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

// 훑을까? 아니면 비교 기준을 짜서 priority Queue를 만들까 
// 그냥 훑자
// Priority를 조사해서, 큰 순으로 넣자( front: 9 - 2 - 1 : back) 이런 식으로. 
typedef struct myQ {
    int index; // location 0~N-1
    int pr; // priority : 1~9
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int T; cin >> T;
    int cnt = 0;
    for (int i = 0; i < T; i++) {
        queue<myQ> q;
        int N, M;
        cin >> N >> M;
        vector<int> v;
        for (int j = 0; j < N; j++) { // 우선 순위 입력받기
            int temp;
            cin >> temp;
            v.push_back(temp);
            q.push({ j, temp });
        }
        cnt = 0;
        sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬

        int len = v.size();
        bool flag = false;

        for (int j = 0; j < len; j++) {
            if (flag) break;
            // 큐에, v의 우선순위에 해당하는 요소들 다 빼버리기.
            while (!q.empty()) {
                int front = q.front().pr;
                if (front == v[j]) { // 빼도 좋은거면
                    cnt++;
                    if (q.front().index == M) {
                        cout << cnt << "\n";
                        flag = true;
                    }
                    q.pop();
                    break;
                }
                else { // 아직 차례가 아니면 맨 뒤로 가
                    q.push(q.front());
                    q.pop();
                }
            }
        }
    }
    return 0;
}