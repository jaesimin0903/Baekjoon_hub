#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n1;
		cin >> n1;
		v.push_back(n1);
	}

	vector<int> lis;

	for (int i = 0; i < N; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), v[i]);

		if (it == lis.end()) {
			lis.push_back(v[i]);
		}
		else {
			*it = v[i];
		}
	}

	cout << lis.size();

	return 0;
}
