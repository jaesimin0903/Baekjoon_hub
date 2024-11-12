#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianPriorityQueue {
private:
	priority_queue<int> left_half; // 최대 힙
	priority_queue<int, vector<int>, greater<int>> right_half; // 최소 힙

public:
	// 새로운 요소 추가
	void push(int value) {
		// 최대 힙에 먼저 추가하고, 균형을 맞추기 위해 이동
		if (left_half.empty() || value <= left_half.top()) {
			left_half.push(value);
		}
		else {
			right_half.push(value);
		}

		// 두 힙의 크기를 맞춰서 중간값 계산이 가능하도록 조정
		if (left_half.size() > right_half.size() + 1) {
			right_half.push(left_half.top());
			left_half.pop();
		}
		else if (right_half.size() > left_half.size()) {
			left_half.push(right_half.top());
			right_half.pop();
		}
	}

	// 중간값 반환
	int getMedian() const {
		if (left_half.size() > right_half.size()) {
			return left_half.top(); // 홀수 개면 최대 힙의 루트가 중간값
		}
		else {
			// 짝수 개면 두 힙의 루트 중 작은 값인 left_half의 루트를 반환
			return left_half.top();
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	MedianPriorityQueue mpq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		mpq.push(n);
		cout << mpq.getMedian() << '\n';
	}

	return 0;
}
