#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구해보세요
    // dp[1] = 1
    // dp[2] = 2 # 1+1, 2
    // dp[3] = 4 # 1+1+1, 2+1, 3, 1+2
    // dp[4] = 7 # 1+1+1+1, 1+1+2, 1+3, 2+2, 3+1, 2+1+1, 1+2+1
    // dp[5] = 5 # 1+1+1+1+1, 1+1+1+2, 1+1+3, 2+2+1, 2+3
    // 아 순서 다르면 다른걸로 치는구나 ㅇㅋ; 그럼 걍 구분 안하고 다 더하면 되게따
    //
    int T;
    cin >> T;
    
    vector<int> dp;
    vector<int> test;
    dp.push_back(0); //dp0
    dp.push_back(1); //dp1
    dp.push_back(2); //dp2
    dp.push_back(4); //dp3
    
    for (int i = 4; i <= 11; i++) {
        int tmp = 0;
        tmp = dp[i - 3] + dp[i - 2] + dp[i - 1];
        dp.push_back(tmp);
    }

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        test.push_back(n);
    }

    for (int i = 0; i < T; i++) {
        cout << dp[test[i]] << "\n";
    }

    return 0;
}