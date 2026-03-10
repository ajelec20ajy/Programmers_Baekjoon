#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<long long> dp;
    dp.push_back(0); // dp0
    dp.push_back(1); // dp1
    dp.push_back(2); // dp2
    // 점화식 = dp = dp[n-1]+dp[n-2] ;; 오른쪽끝이 하나 남았냐 두개남았냐

    for (int i = 3; i <= N; i++) {
        dp.push_back((dp[i - 1] + dp[i - 2])%10007);
    }

    cout << dp[N];

    return 0;
}