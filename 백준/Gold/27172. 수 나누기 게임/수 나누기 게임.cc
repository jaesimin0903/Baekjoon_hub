#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> v;
int card[1000010];
int point[1000010];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
		card[n] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = v[i] * 2; j < 1000001; j += v[i]) {
			if (card[j] == 1) {
				point[v[i]]++;
				point[j]--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << point[v[i]] << " ";
	}
	
	return 0;
}
