#include <iostream>
#include <vector>

using namespace std;

class myDeque {
private:
	vector<int> md;
public:
	myDeque() {

	}
	void size() {
		cout << md.size() << "\n";
	}
	void push_front(int n) { // 맨 앞 삽입
		md.insert(md.begin(), 1, n);
	}
	void push_back(int n) { // 맨 뒤 삽입
		md.push_back(n);
	}
	void pop_front() { // 맨 앞 출력하고 제거. 없으면 -1
		if (md.empty()) {
			cout << "-1\n";
		}
		else {
			cout << md.front() << "\n";
			md.erase(md.begin());
		}
	}
	void pop_back() { // 맨 뒤 출력하고 제거. 없으면 -1
		if(md.empty()) cout << "-1\n";
		else {
			cout << md.back() << "\n";
			md.pop_back();
		}
	}
	void empty() {
		cout << (md.empty() ? 1 : 0) << "\n";
	}
	void front() {
		if (md.empty()) cout << "-1\n";
		else cout << md.front() << "\n";
	}
	void back() {
		if (md.empty()) cout << "-1\n";
		else {
			cout << md.back() << "\n";
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	myDeque dq;
	int N;
	cin >> N;
	while (N--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (cmd == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (cmd == "pop_front") {
			dq.pop_front();
		}
		else if (cmd == "pop_back") {
			dq.pop_back();
		}
		else if (cmd == "size") {
			dq.size();
		}
		else if (cmd == "empty") {
			dq.empty();
		}
		else if (cmd == "front") {
			dq.front();
		}
		else if (cmd == "back") {
			dq.back();
		}
	}
	return 0;
}