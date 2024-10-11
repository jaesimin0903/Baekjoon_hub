#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int N, M, K;
int ans = -1;
int map[1010][1010];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// Out of bounds 체크 함수
bool oob(int y, int x) {
    return y < 0 || x < 0 || y >= N || x >= M;
}

void bfs(int y, int x) {
    // 3차원 visited 배열: [y][x][벽을 몇 개 부쉈는지]
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(K + 1, false)));
    
    queue<tuple<int, int, int, int>> q; // (y, x, 벽을 부순 횟수, 이동 횟수)
    q.push({ y, x, 0, 1 });
    visited[y][x][0] = true;

    while (!q.empty()) {
        int cy, cx, broken, cnt;
        tie(cy, cx, broken, cnt) = q.front();
        q.pop();

        if (cy == N - 1 && cx == M - 1) {
            ans = cnt;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (oob(ny, nx)) continue;

            // 벽을 부술 수 있는 경우
            if (map[ny][nx] == 1 && broken < K && !visited[ny][nx][broken + 1]) {
                visited[ny][nx][broken + 1] = true;
                q.push({ ny, nx, broken + 1, cnt + 1 });
            }
            // 벽이 아니고 방문하지 않은 경우
            if (map[ny][nx] == 0 && !visited[ny][nx][broken]) {
                visited[ny][nx][broken] = true;
                q.push({ ny, nx, broken, cnt + 1 });
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
        }
    }

    bfs(0, 0);

    cout << ans;
    return 0;
}
