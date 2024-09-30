#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // memset을 위한 헤더

using namespace std;

#define INF 1e9
#define N 130
int n;
// 상하좌우 이동을 위한 방향 배열
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int map[N][N];

int getMinTime(int sy, int sx, int ey, int ex) {
    bool visited[N][N];
    int minTime[N][N];
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // 배열 초기화
    memset(visited, false, sizeof(visited)); // 방문 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            minTime[i][j] = INF;
        }
    }

    // 시작점 초기화
    minTime[sy][sx] = 0;
    pq.push({0, sy, sx });

    while (!pq.empty()) {
        vector<int> current = pq.top();
        pq.pop();

        int y = current[1];
        int x = current[2];
        int time = current[0];

        // 이미 방문했다면 무시
        if (visited[y][x]) continue;
        visited[y][x] = true;

        // 목적지에 도달했다면 최소 시간 반환
        if (y == ey && x == ex) {
            return time;
        }

        // 상하좌우로 이동
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위 검사
            if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                int newTime = time + map[ny][nx]; // 이동하는 비용 추가

                // 새로운 위치로 이동하는 시간이 더 짧다면 갱신
                if (newTime < minTime[ny][nx]) {
                    minTime[ny][nx] = newTime;
                    pq.push({newTime, ny, nx });
                }
            }
        }
    }

    return -1; // 경로를 찾을 수 없는 경우
}

int main() {
    int T = 0;

    while (true) {
        T++;
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        // 시작 위치의 비용을 포함하여 출력
        cout << "Problem " << T << ": " << getMinTime(0, 0, n - 1, n - 1) + map[0][0] << "\n";
    }
    return 0;
}
