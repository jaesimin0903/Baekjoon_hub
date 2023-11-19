#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
int v[52][52];
vector<vector<bool>> visited;
int ans = 0;

bool valid(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < N;
}

bool bfs(int startY, int startX) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> a;
    q.push({startY, startX});
    visited[startY][startX] = true;

    int sum = 0;
    bool isMoved = false;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        a.push_back({y, x});
        sum += v[y][x];

        int dy[4] = {-1, 1, 0, 0};
        int dx[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (valid(ny, nx) && !visited[ny][nx]) {
                int diff = abs(v[y][x] - v[ny][nx]);
                if (diff >= L && diff <= R) {
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                    isMoved = true;
                }
            }
        }
    }

    if (isMoved) {
        int avg = sum / a.size();
        for (auto &p : a) {
            v[p.first][p.second] = avg;
        }
    }

    return isMoved;
}

int main() {
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    visited.resize(N, vector<bool>(N, false));

    bool isUpdated;
    do {
        isUpdated = false;
        for (int i = 0; i < N; i++) {
            fill(visited[i].begin(), visited[i].end(), false);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && bfs(i, j)) {
                    isUpdated = true;
                }
            }
        }

        if (isUpdated) ans++;
    } while (isUpdated);

    cout << ans << endl;

    return 0;
}
