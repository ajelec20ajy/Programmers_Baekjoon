#include <iostream>
#include <stack>
#include <vector>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v, v2; // v1: reference(입력값). v2 : 뭐지
    vector<char> ans; // +, - 입력할거
    stack<int> s; // 스택
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp; cin >> temp;
        v.push_back(temp);
    }
    
    // v[i] 만날때까지 계속 스택에 집어넣음.
    // 아니면, v[i] 만날때까지 계속 스택에서 뺌. -> 그럼 처음에는 어떡하죠?
    // -> 만약 v[i]가 stack의 Top보다 크다면 스택에 넣고, 아니면 스택에서 뺴야됌
    // 아아아아 그러면은 약간 제한이 있다? 뭐냐면은 1, 2, 3 넣고서 4를 만나서 뺴고 5넣고 6넣었으면, 이제 다음으로 반드시 5거나 78910이어야함.
    // 예를 들어서 그러면, front > v1[i]면 바로 No 출력후 함수반환
    // 

    int next = 1;

    for (int i = 0, j = 0; j < N; ) {

        while (next <= v[i]) {
            s.push(next++);
            ans.push_back('+');
        }

        if (!s.empty() && s.top() == v[i]) {
            s.pop();
            ans.push_back('-');
            i++;
            j++;
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }

    for (char c : ans) {
        cout << c << "\n";
    }

    return 0;
}