#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int target; // 만들 값
    int N; // 동전 종류 갯수
    vector<int> coins; // 동전 리스트
    
    cin >> N >> target;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    // 걍 내림차순 정렬 떄리고
    // coins[i] < target인 지점 찾아다가, 젤 큰거 먼저 여러개 떄려부으면되지 뭐

    sort(coins.begin(), coins.end(), greater<int>()); // 내림차순

    int start = 0; // 넣기 시작할 동전(중에 젤 큰것)
    for (int i = 0; i < N; i++) {
        if (target >= coins[i]) {
            start = i;
            break;
        }
    }

    vector<int> coins2; // 넣을 동전 종류들!

    for (int i = start; i < N; i++) {
        coins2.push_back(coins[i]);
    }

    int len = coins2.size();
    int cnt = 0; // 들어간 동전 카운터
    int last = target; // 남은 액수
    for (int i = 0; i < len; i++) {
        int j = last / coins2[i];
        last = last - coins2[i] * j;
        cnt += j;
    }

    cout << cnt;

    return 0;
}