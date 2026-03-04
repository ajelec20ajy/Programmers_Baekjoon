#include <iostream>
#include <string>
#include <vector>

using namespace std;

class queue {
private:
	vector<int> q;
	int f;
public:
    queue() {
        f = 0;
    }

    void push(int r) {
        q.push_back(r);
    }

    int pop() {
        if (empty()) return -1;

        int ret = q[f];
        f++;
        return ret;
    }

    int size() {
        return q.size() - f;
    }

    bool empty() {
        return f == q.size();
    }

    int front() {
        if (empty()) return -1;
        return q[f];
    }

    int back() {
        if (empty()) return -1;
        return q.back();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue q;
    int N;
    cin >> N;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int val;
            cin >> val;
            q.push(val);
        }
        else if (cmd == "pop") {
            cout << q.pop() << "\n"; // endl 대신 \n 권장
        }
        else if (cmd == "size") {
            cout << q.size() << "\n";
        }
        else if (cmd == "empty") {
            cout << q.empty() << "\n";
        }
        else if (cmd == "front") {
            cout << q.front() << "\n";
        }
        else if (cmd == "back") {
            cout << q.back() << "\n";
        }
    }

	return 0;
}