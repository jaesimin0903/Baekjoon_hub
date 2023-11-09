#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#include<cmath>
using namespace std;


int main() {
	int n;
	vector<int> room;
	int b, c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		room.push_back(num);
	}
	cin >> b >> c;

	long long int answer = 0;
	for (int i = 0; i < n; i++) {
		if (room[i] > b) {
			answer += (room[i]-b) / c;
			if ((room[i] - b) % c != 0) answer++;
			answer++;
			}
		else {
			answer += 1;
		}

	}

	cout << answer;
	return 0;
}

