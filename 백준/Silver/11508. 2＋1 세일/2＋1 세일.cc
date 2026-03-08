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

    int N;
    vector<int> list;
    vector<Node> myNode;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        list.push_back(tmp);
    }

    sort(list.begin(), list.end(), greater<int>());

    int last = list.size() % 3; // 1개 남는지, 2개 남는지, 딱 맞아 떨어지는지.
    int len = 0;
    int cnt = 0;
    switch (last) {
    case 0:
        len = list.size() / 3;
        break;
    case 1:
    case 2:
        len = (list.size() / 3) + 1;
        break;
    default:
        break;
    }

    for (int i = 0; i < len; i++) {
        int st = 3 * i;
        if (last && i == (len -1)) {
            if (last == 1)
                myNode.push_back({ list[st], 0, 0 });
            else
                myNode.push_back({ list[st], list[st + 1], 0 });       
        }
        else {
            myNode.push_back({ list[st], list[st + 1], list[st + 2] });
        }
    }

    int sum = 0;
    int len2 = myNode.size();
    for (int i = 0; i < len2; i++) {
        if (i == (len2 - 1)) {
            if (last == 1)
                sum += myNode[i].x;
            else if (last == 2)
                sum += (myNode[i].x + myNode[i].y);
            else
                sum += (myNode[i].x + myNode[i].y);
        }
        else {
            sum += (myNode[i].x + myNode[i].y);
        }
    }

    cout << sum;

    return 0;
}