#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());

	long long answer = 0;

	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			auto l = lower_bound(v.begin() + j+1, v.end(), -(v[i] + v[j]));
			auto r = upper_bound(v.begin() + j+1, v.end(), -(v[i] + v[j]));
			answer += r - l;
		}
	}

	cout << answer;

	return 0;
}