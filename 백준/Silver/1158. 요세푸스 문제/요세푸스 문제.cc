#include <iostream>
#include <queue>
#include <stdint.h>

using namespace std;
class myQueue {
private:
	queue<uint16_t> mq;
	uint16_t cnt;
public:
	myQueue(uint16_t total) {
		cnt = 0;
		for (int i = 0; i < total; i++) {
			mq.push(i + 1);
		}
	}
	void check(uint16_t num) {
		do {
			cnt++;
			if (cnt == num) {
				cout << mq.front() << "";
				mq.pop();
				break;
			}
			else {
				mq.push(mq.front());
				mq.pop();
			}
		} while (1);
		cnt = 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*
	깨달았다. 그냥 선입선출 큐에 순서대로(1부터) 넣고, 한명 뺄 때 마다 검증함.
	검증: 한명 뺄 때 마다 cnt++하고, cnt == k일때 그 사람 빼버림.
	      만약, cnt != k면 그 사람 다시 큐 맨 뒤로 보냄
	*/
	
	uint16_t N, K;
	uint16_t cnt = 0;
	cin >> N >> K;
	myQueue q(N);
	cout << "<";
	for (int i = 1; i <= N; i++) { // q만들기
		q.check(K);
		if (i <= (N - 1)) {
			cout << ", ";
		}
		else {
			cout << ">";
		}
	}

	return 0;
}