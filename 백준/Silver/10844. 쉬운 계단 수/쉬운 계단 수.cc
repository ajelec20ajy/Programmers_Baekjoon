#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
     와 dp를 앞숫자기준으로 짜는거구나
     dp[N][k]를, 길이가 N일때 맨뒤 앞자리 수가 k일때의 그걸로 하자.
    */
    int N; cin >> N;
    long long dp[101][10];

    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    //dp[n][k] = dp[n-1][k-1]+dp[n-1][k+1]
    //dp[n][0] = dp[n-1][1]
    //dp[n][9] = dp[n-1][8]
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) dp[i][0] = dp[i - 1][1] % 1000000000;
            else if (j == 9) dp[i][9] = dp[i - 1][8] % 1000000000;
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
            }
        }
    }

    int sum = 0;
    for (int n : dp[N]) {
        sum = (sum + n) % 1000000000;
    }

    cout << sum;
    return 0;
}