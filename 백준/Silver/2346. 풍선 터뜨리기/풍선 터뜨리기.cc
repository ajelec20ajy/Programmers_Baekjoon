#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// 1 2 3 4 .... 5 6 7
// 1 왼쪽은 7이 있고, 7 오른쪽은 1이있음. 
// 각 풍선은 -N~N 사이의 정수가 적힌 종이가 하나씩있음. 양수면 적힌 숫자만큼 오른쪽으로 가고, 음수면 왼쪽으로 감.
// 원형 연결 리스트를 쓰면 좋을거같아.
// 만약 풍선이 터지면, 배열에서 빼버려

using namespace std;

typedef struct MyNode {
    int num;
    int paper;
    MyNode* left;
    MyNode* right;
} MyNode;

class myCircle {
private:
    MyNode* now;
public:
    myCircle(int N, const vector<int>& papers) {
        MyNode* head = new MyNode{ 1, papers[0], nullptr, nullptr };
        now = head;
        MyNode* curr = head;
        for (int i = 2; i <= N; i++) {
            MyNode* newNode = new MyNode{ i, papers[i - 1], curr, nullptr };
            curr->right = newNode;
            curr = newNode;
        }
        curr->right = head;
        head->left = curr;
    }

    void solve(int N) {
        for (int i = 0; i < N; i++) {
            // 현재 풍선 번호 출력
            cout << now->num << " ";

            // 마지막 풍선이면 이동할 필요 없음
            if (i == N - 1) break;

            // 종이 값 확인 및 리스트에서 제거
            int step = now->paper;
            MyNode* target = now;

            target->left->right = target->right;
            target->right->left = target->left;

            // 다음 위치로 이동
            if (step > 0) {
                now = target->right;
                for (int j = 1; j < step; j++) now = now->right;
            }
            else {
                now = target->left;
                for (int j = 1; j < -step; j++) now = now->left;
            }

            // 메모리 해제  생략
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> papers(N);
    for (int i = 0; i < N; i++) {
        cin >> papers[i];
    }

    myCircle mc(N, papers);
    mc.solve(N);

    return 0;
}