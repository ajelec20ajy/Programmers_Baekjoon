#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// ascii 코드로 알파벳과 특수문자 구분하자.
// 연산자는 + - * / %가 있겠지?
// 그냥 스택에 넣고, 연산자를 만났을 때 피연산자 두개를 POP해서 다시 PUSH하면 댈듯

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<double> s; // 연산 과정을 담을 스택
    vector<int> v; // 피연산자들(A, B, )
    int N; cin >> N;
    string x;
    cin >> x;

    for (int i = 0; i < N; i++) {
        int y; cin >> y;
        v.push_back(y);
    }

    int len = x.length();
    for (int i = 0; i < len; i++) {
        if (x[i] >= 0x41 && x[i] <= 0x5A) { // 피연산자면
            s.push(v[x[i] - 0x41]);
        }
        else { // 연산자면
            double nn, mm; // 스택에서 뽑을 두 숫자를 저장
            nn = s.top(); s.pop();
            mm = s.top(); s.pop();
            switch (x[i]) {
            case '+' :
                s.push(mm + nn);
                break;
            case '-' :
                s.push(mm - nn);
                break;
            case '*' :
                s.push(mm * nn);
                break;
            case '/' :
                s.push(mm / nn);
                break;
            default:
                break;
            }

        }
    }

    cout << fixed;   
    cout.precision(2);
    cout << s.top();

    return 0;
}