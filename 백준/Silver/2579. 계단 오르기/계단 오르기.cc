#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> E;
    vector<int> v; // dp

    E.push_back(0);
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        E.push_back(tmp);
    }

    v.push_back(0); // v[0] = 0
    v.push_back(E[1]); // v[1]
    v.push_back(E[1] + E[2]); // v[2]
    v.push_back(max(E[1] + E[3], E[2] + E[3])); // v[3]

    
    for (int i = 4; i <= N; i++) {
        v.push_back(E[i] + max(v[i-2], v[i - 3] + E[i - 1]));
    }


    cout << v[N];

    return 0;
}