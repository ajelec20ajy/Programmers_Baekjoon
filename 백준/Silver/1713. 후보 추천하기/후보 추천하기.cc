/*
한민선은 완전 바보 펭귄이다
동의하십니까??
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct Student {
    int num; // 학생 번호
    int cnt; // 추천 횟수
    int time; // 추천한 최초시ㅅ각
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Student> frame;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        bool found = false;

        // 이미 사진틀에 있는지 확인
        for (auto& s : frame) {
            if (s.num == x) {
                s.cnt++;
                found = true;
                break;
            }
        }

        if (found) continue;

        // 사진틀 여유 있음
        if (frame.size() < N) {
            frame.push_back({ x,1,i });
        }

        // 사진틀 가득 참
        else {
            sort(frame.begin(), frame.end(), [](Student a, Student b) {
                if (a.cnt == b.cnt) // 중복된게 있다면
                    return a.time < b.time;
                return a.cnt < b.cnt;
                });

            frame.erase(frame.begin());

            frame.push_back({ x,1,i });
        }
    }

    vector<int> ans;

    for (auto s : frame)
        ans.push_back(s.num);

    sort(ans.begin(), ans.end());

    for (int x : ans)
        cout << x << " ";

    return 0;
}