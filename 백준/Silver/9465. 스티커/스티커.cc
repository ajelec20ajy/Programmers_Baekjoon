#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int s[2][100001];
int dp[2][100001];

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> s[i][j];
            }
        }

        dp[0][1] = s[0][1];
        dp[1][1] = s[1][1];

        if (n >= 2) {
            dp[0][2] = dp[1][1] + s[0][2];
            dp[1][2] = dp[0][1] + s[1][2];
        }

        for (int j = 3; j <= n; j++) {
            dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + s[0][j];
            dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + s[1][j];
        }

        cout << max(dp[0][n], dp[1][n]) << "\n";
    }

    return 0;
}