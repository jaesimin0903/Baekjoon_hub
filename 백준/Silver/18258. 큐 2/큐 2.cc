#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(void) {
	int N, i;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string command = "";
	int num;
	cin >> N;
	stack<int> stack;
	queue<int> queue;
	for (i = 0;i < N;i++) {
		cin >> command;
		if (command == "push") {
			cin >> num;
			queue.push(num);
		}
		else if (command == "pop") {
			if (queue.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << queue.front() << '\n';
				queue.pop();
			}
		}
		else if (command == "size") {
			cout << queue.size() << '\n';
		}
		else if (command == "empty") {
			if (queue.empty())cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (command == "front") {
			if (queue.empty()) {
				cout << -1 << '\n';
			}
			else cout << queue.front()<<'\n';
		}
		else if (command == "back") {
			if (queue.empty()) {
				cout << -1 << '\n';
			}
			else cout << queue.back()<<'\n';
		}
		else break;
	}

	return 0;
}