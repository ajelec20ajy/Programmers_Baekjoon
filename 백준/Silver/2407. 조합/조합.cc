#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string add(string num1, string num2) {
    string result = "";
    int sum = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || sum > 0) {
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';

        result += (sum % 10) + '0';
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    nCr = (n-1)Cr + (n-1)C(r-1) 네 이게 점화식이네용
    */
    int n, m;
    cin >> n >> m;

    string arr[101][101];

    for (int i = 0; i <= n; i++) {
        arr[i][0] = "1";
        arr[i][i] = "1";
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            arr[i][j] = add(arr[i - 1][j], arr[i - 1][j - 1]);
        }
    }

    cout << arr[n][m];


    return 0;
}