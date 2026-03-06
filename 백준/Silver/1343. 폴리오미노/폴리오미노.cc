#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 순위 : 사전순으로 앞서야함. 
    // 자 그럼, 단위를 끊어야지. '.'을 기준으로 정렬하자.
    // .이 나오기 전까지, AAAA가 BB보다 앞에 있는게 좋은거잖아?
    // 그리디로 하나씩 해보면 될듯.
    // 어케하나면, X가 연속되는 개수를 구하고, 그 개수를 AAAA, BB로 채울 수 있는지 판단해.
    
    int aaaa = 4;
    int bb = 2;

    string x;
    cin >> x;

    int len = x.length();
    int cnt = 0;
    for (int i = 0; i <= len; i++) {
        if ((x[i] == '.' || i == len) && (cnt != 0)) {
            if (cnt % 2) {// 어짜피 안들어가
                cout << "-1\n";
                return 0;
            }
            cnt = 0;
        }
        else {
            if(x[i] != '.') cnt++;   
        }
    }
    for (int i = 0; i <= len; i++) {
        if ((x[i] == '.' || i == len) && (cnt != 0)) {
            // AAAA를 대보고 안되면 BB를 대면 되지 aaaa가 많을수록 사전순도 당연히 앞서겠지?? aaaa가 앞에있을거니깐!
            // 이제 그리디 돌리고
            int a = cnt / 4;
            int b = (cnt - a * 4) / 2;
            // 출력하자
            for (int j = 0; j < a; j++) {
                cout << "AAAA";
            }
            for (int j = 0; j < b; j++) {
                cout << "BB";
            }
            if (x[i] == '.') cout << ".";
            cnt = 0;
        }
        else if (x[i] == '.' && cnt == 0) {
            cout << ".";
        }
        else {
            if (x[i] != '.') cnt++;
        }
    }
    return 0;
}