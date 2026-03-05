#include <iostream>
#include <queue>

using namespace std;
class myQueue {
private:
	queue<int> mq;
public:
	myQueue(int total) {
		for (int i = 0; i < total; i++) {
			mq.push(i + 1);
		}
	}
	int qsize() {
		return mq.size();
	}
	void next() {
		mq.pop();
		mq.push(mq.front());
		mq.pop();
	}

	void print() {
		cout << mq.front() << "";
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*
	그냥 큐 사이즈가 1이 될 때 까지... front 버리고, 그 다음 front를 맨뒤로 삽입하는거 반복하면 대자나
	*/
	
	int N;
	cin >> N;
	myQueue q(N);
	
	while (q.qsize() != 1) {
		q.next();
	}

	q.print();

	return 0;
}