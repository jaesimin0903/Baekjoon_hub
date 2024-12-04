#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
int T;
int map[60][60];
bool visited[60][60];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool oob(int y, int x) {
	return y < 0 || x < 0 || y >= N || x >= M;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> N >> K;
		int answer = 0;

		for (int i = 0; i < 60; i++) {
			for (int j = 0; j < 60; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < K; i++) {
			int r, c;
			cin >> c >> r;

			map[r][c] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 1) continue;
				if (visited[i][j]) continue;
				queue<pair<int, int>>q;
				answer++;

				q.push({ i,j });
				visited[i][j] = true;

				while (!q.empty()) {
					int curY = q.front().first;
					int curX = q.front().second;
					q.pop();
					for (int d = 0; d < 4; d++) {
						int ny = curY + dy[d];
						int nx = curX + dx[d];

						if (oob(ny, nx))continue;
						if (map[ny][nx] != 1)continue;
						if (visited[ny][nx]) continue;

						visited[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
		}

		cout << answer<<"\n";

	}

	return 0;
}