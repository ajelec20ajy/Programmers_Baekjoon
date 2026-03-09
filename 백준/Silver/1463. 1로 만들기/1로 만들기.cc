#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    cin >> N;
    vector<int> dp;

    dp.push_back(0); // dp[0]
    dp.push_back(0); // dp[1]
    dp.push_back(1); // dp[2]
    dp.push_back(1); // dp[3]
    
    for (int i = 4; i <= N; i++) {
        int tmp;
        if (i % 3 == 0) {
            if (i % 2 == 0) {
                tmp = min(min(1 + dp[i / 2], 1 + dp[i / 3]), 1 + dp[i - 1]);
            }
            else {
                tmp = min(1 + dp[i / 3], 1+dp[i-1]);
            }
        }
        else if (i % 2 == 0) {
            tmp = min(1 + dp[i / 2], 1 + dp[i - 1]);
        }
        else {
            tmp = 1 + dp[i - 1];
        }
        dp.push_back(tmp);
    }

    cout << dp[N];

    return 0;
}