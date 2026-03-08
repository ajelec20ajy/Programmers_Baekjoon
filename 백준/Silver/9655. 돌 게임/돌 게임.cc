#include <iostream>

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
    // dp[7] : 1
    // dp[8] : 0
    // dp[9] : 1
    // 그냥 짝수면 창영이가 이기는거 아님?


    int N; cin >> N;

    if (N % 2) cout << "SK";
    else cout << "CY";

    return 0;
}