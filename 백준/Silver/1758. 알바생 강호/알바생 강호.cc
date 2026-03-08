#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> tips;
    // 바로 보였다. 그것은 바로, tips[i] - (i-1) = 0이되는 시점에서 i보다 큰 놈들만 팁주게하면댐
    // 통큰손님들한테만 받고 째째한 손님들은 0원받아도 되자나
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        tips.push_back(temp);
    }

    sort(tips.begin(), tips.end(), greater<int>());

    int target = 0; // 팁을 받을 수 있는 순서가 몇번째인가
    int all_pos = 0; // 전부에게 팁을 받는가?
    for (int i = 0; i < N; i++) {
        if ((tips[i] - i) <= 0) {
                target = i; // 순서 = i+1
                break;
        }
        else if (i == N - 1) {
            all_pos = 1;
        }
    }
    if (all_pos) target = N;

    long long sum = 0;
    for (int i = 0; i < target; i++) {
        int tip = ((tips[i]) - (i));
        if (tip<=0) continue;
        else {
            sum += ((tips[i]) - (i));
        }
    }

    cout << sum;

    return 0;
}