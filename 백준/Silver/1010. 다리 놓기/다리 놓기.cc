#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node {
    int x, y, z;
}Node;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    // 암튼 구해야되는건 mCn이자나
    // mCn = (m-1)C(n-1) + (m-1)Cn이다. 이게 점화식이네
    // x[p][q]가 pCq라고 할까?
    // x[1][0] = 0; x[1][1] = 1; x[2][1] = 2; x[2][2] = 1; x[3][1] = 3; x[3][2] = 3; x[3][3] = 1;
    // x[p][q] = x[p-1][q-1] + x[p-1][q]

    long long x[31][31] = { 0, };
 
    for (int i = 0; i <= 30; i++) { // nC0과 nCn 채우기
        x[i][0] = 1;
        x[i][i] = 1;
    }
    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j < i; j++) {
            x[i][j] = x[i - 1][j - 1] + x[i - 1][j];
        }
    }
    
    for (int j = 0; j < T; j++) {
        int N, M;
        cin >> N >> M;

        cout << x[M][N] << "\n";
    }
    return 0;
}