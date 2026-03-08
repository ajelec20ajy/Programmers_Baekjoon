#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //dp[n] : 돌이 n개일때 1이면 상근이가 이기고, 0이면 창영이가 이김

    // dp[1] : 1
    // dp[2] : 0
    // dp[3] : 1
    // dp[4] : 0
    // dp[5] : 1
    // dp[6] : 0
    // 그냥 짝수면 창영이가 이기는거 아님? 1하고 3밖에 없으니깐. 3은 결국 걍 자기턴으로 돌아온거자나
    // 억지 dp 돌려볼까?
    // dp[1] = 1, dp[2] = 0, dp[n] = dp[n-1]-dp[n-2].. n이 홀수면 -1이고, 짝수면 1이네.
    // dp[n] = (1+dp[n-1]-dp[n-2])? 0 : 1
    
    vector<int> dp;
    dp.push_back(0); // 의미없는데 그냥 인덱스맞추기위함
    dp.push_back(1); // dp[1]
    dp.push_back(0); // dp[2]
    dp.push_back(1); // dp[3]
    
    int N; cin >> N;

    /*
    if (N % 2) cout << "SK";
    else cout << "CY";
    */

    for (int i = 4; i <= N; i++) {
        dp.push_back((1 + dp[i - 1] - dp[i - 2]) ? 0 : 1);
    }

    if (dp[N]) cout << "SK";
    else cout << "CY";

    return 0;
}