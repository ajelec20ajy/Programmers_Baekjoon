#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 오랜만에 dp로군
    // 그냥 그리디 + dp하면 댈거같은데?
    // 와~~~~~~ "연속된" 이었네~~~ 스고이~~
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    vector<long long> dp;

    // 1. dp를 어케 정할 것인가
    // 후보 (1) n개의 합 (2) 끝이 n번째인 경우 (3) 합이 n인것 (4) 음 그냥 (2)가 젤 나을거같지 딱봐도

    // 2. dp 수식 세우기
    // 그럼 모 간단하게
    // dp[n] = dp[n-1]+v[n] vs v[n]이면 되네.

    dp.push_back(0);

    dp.push_back(v[0]); // dp[1]

    for (int i = 2; i <= n; i++) {
        long long max;
        max = dp[i - 1] + v[i - 1] > v[i - 1] ? dp[i - 1] + v[i - 1] : v[i - 1];
        dp.push_back(max);
    }

    long long ans = *max_element(dp.begin()+1, dp.end());
    cout << ans;

    return 0;
}