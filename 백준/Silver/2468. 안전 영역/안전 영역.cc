#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N;
int day = 0;
int ans = 0;
int maxCount = 0;
int map[110][110];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };

bool oob(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= N;
}

void bfs(int d) {
	bool v[110][110];
	memset(v, false, sizeof(v));
	queue<pair<int, int>> q;

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j]) continue;
			if (map[i][j] <= d) continue;
			
			count++;
			q.push({ i,j });
			v[i][j] = true;
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int dd = 0; dd < 4; dd++) {
					int ny = y + dy[dd];
					int nx = x + dx[dd];
					if (oob(ny, nx))continue;
					if (v[ny][nx])continue;
					if (map[ny][nx] <= d) continue;
					q.push({ ny,nx });
					v[ny][nx] = true;
				}
			}
		}
	}

	if (maxCount < count) {
		ans = d;
		maxCount = count;
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			day = max(day, n);
			map[i][j] = n;
		}
	}

	for (int i = 0; i <= day; i++) {
		bfs(i);
	}
	cout << maxCount;
	return 0;
}