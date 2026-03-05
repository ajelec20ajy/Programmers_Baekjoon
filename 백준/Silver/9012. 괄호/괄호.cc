#include <iostream>
#include <stack>
#include <vector>
#include <stdint.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	stack<uint8_t> st;
	int N;
	cin >> N;

	while (N--) {
		string arr;
		cin >> arr;
		uint8_t flag = 1;
		for (char c : arr) {
			if (c == '(') st.push(1);
			else {
				if (st.empty()) {
					cout << "NO\n";
					flag = 0;
					break;
					// 에러
				}
				else {
					st.pop();
				}
			}
		}
		if (flag && st.empty()) cout << "YES\n";
		else if (flag) cout << "NO\n";
		while (!st.empty()) {
			st.pop();
		}
	}
	return 0;
}