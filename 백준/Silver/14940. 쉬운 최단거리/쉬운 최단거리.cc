#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

queue<pair<int, int>> q;

int N, M,H;


int v[1000][1000];
int visited[1000][1000];
int ans[1000][1000];

bool endd = false;
#include <unordered_map> 


void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	visited[i][j] = 1;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int a = 0; a < 4; a++) {
			int nx = x + dx[a];
			int ny = y + dy[a];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (visited[ny][nx] == 0 && v[ny][nx] != 0) {
					visited[ny][nx] = visited[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main() {

	cin >> N >> M;

	int tx, ty;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				ty = i;
				tx = j;
			}
		}
	}
	
	bfs(ty, tx);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0 && v[i][j] == 0) {
				cout << 0 << " ";
			}
			else if (visited[i][j] == 0 && v[i][j] != 0) {
				cout << -1 << " ";
			}
			else cout << visited[i][j]-1 << " ";
		}
		cout << "\n";
	}

	return 0;
}