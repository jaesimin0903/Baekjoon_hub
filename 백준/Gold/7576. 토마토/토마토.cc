#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M;

queue<pair<int, int>> q;
vector<vector<int>>v(1000, vector<int>(1000, 0));

void bfs(vector<vector<int>>&v) {
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		if (i - 1 >= 0 && v[i - 1][j] == 0) {
			v[i - 1][j] = v[i][j] + 1;
			q.push({ i - 1,j });
		}
		if (j - 1 >= 0 && v[i ][j-1] == 0) {
			v[i ][j-1] = v[i][j] + 1;
			q.push({ i ,j-1 });
		}
		if (i +1 <N && v[i + 1][j] == 0) {
			v[i + 1][j] = v[i][j] + 1;
			q.push({ i + 1,j });
		}
		if (j+ 1 <M && v[i][j+1] == 0) {
			v[i][j+1] = v[i][j] + 1;
			q.push({ i,j+1 });
		}

	}
}
int main() {

	//int N, M;
	cin >> M >> 
		N;



	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			v[i][j] = num;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(v[i][j]==1)q.push({ i,j });
		}
	}

	bfs(v);
	int maxx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
			if (maxx < v[i][j]) maxx = v[i][j];
		}
		
	}

	cout << maxx - 1 << "\n";

	return 0;
}
