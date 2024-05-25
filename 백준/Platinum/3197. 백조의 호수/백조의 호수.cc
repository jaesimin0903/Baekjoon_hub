#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int R, C;

vector<string> m;
int parent[1510 * 1510];
bool visited[1510][1510];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축 (Path compression)
}

void unite(int x, int y) {
    int pa = find(x);
    int pb = find(y);
    if (pa != pb) { // pa와 pb가 다를 때만 합침
        if (pa < pb) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
        }
    }
}

bool is_same_parent(int x, int y) {
    return find(x) == find(y);
}

bool check(int ny, int nx) {
    return (ny < 0 || nx < 0 || ny >= R || nx >= C);
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < 1510 * 1510; i++) {
        parent[i] = i;
    }

    vector<pair<int, int>> bird;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        m.push_back(str);
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'L') bird.push_back({ i, j });
        }
    }

    queue<pair<int, int>> water;
    queue<pair<int, int>> next_water;

    // 초기 물 위치 및 Union-Find 초기화
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] == '.' || m[i][j] == 'L') {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (check(ni, nj)) continue;
                    if (m[ni][nj] == '.' || m[ni][nj] == 'L') {
                        unite(i * C + j, ni * C + nj);
                    } else if (m[ni][nj] == 'X' && !visited[ni][nj]) {
                        water.push({ ni, nj });
                        visited[ni][nj] = true;
                    }
                }
            }
        }
    }

    int year = 0;
    while (true) {
        if (is_same_parent(bird[0].first * C + bird[0].second, bird[1].first * C + bird[1].second)) {
            cout << year << endl;
            return 0;
        }

        while (!water.empty()) {
            int y = water.front().first;
            int x = water.front().second;
            water.pop();
            m[y][x] = '.';

            for (int d = 0; d < 4; d++) {
                int ny = y + dy[d];
                int nx = x + dx[d];
                if (check(ny, nx)) continue;
                if (m[ny][nx] == '.' || m[ny][nx] == 'L') {
                    unite(y * C + x, ny * C + nx);
                } else if (m[ny][nx] == 'X' && !visited[ny][nx]) {
                    next_water.push({ ny, nx });
                    visited[ny][nx] = true;
                }
            }
        }

        // 큐를 비우고 다음 해로 넘기기
        water = next_water;
        while (!next_water.empty()) {
            next_water.pop();
        }

        year++;
    }

    return 0;
}
