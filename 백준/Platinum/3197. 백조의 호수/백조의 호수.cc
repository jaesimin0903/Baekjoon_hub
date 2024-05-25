#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

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
        }
        else {
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

struct Node {
    int r, c;
    Node(int r, int c) : r(r), c(c) {}
};

int main() {
    cin >> R >> C;

    for (int i = 0; i < 1510 * 1510; i++) {
        parent[i] = i;
    }

    vector<Node> bird;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        m.push_back(str);
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == 'L') {
                bird.push_back(Node(i, j));
                m[i][j] = '.'; // 백조의 위치도 물로 간주
            }
        }
    }

    queue<Node> water, next_water;

    // 처음 시작전 부모 초기화 및 물 위치 초기화
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] == '.') {
                water.push(Node(i, j));
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (check(ni, nj)) continue;
                    if (m[ni][nj] == '.') {
                        unite(i * C + j, ni * C + nj);
                    }
                }
            }
        }
    }

    int year = 0;
    while (!is_same_parent(bird[0].r * C + bird[0].c, bird[1].r * C + bird[1].c)) {
        while (!water.empty()) {
            Node current = water.front();
            water.pop();
            for (int d = 0; d < 4; d++) {
                int ni = current.r + dx[d];
                int nj = current.c + dy[d];
                if (check(ni, nj)) continue;
                if (m[ni][nj] == 'X' && !visited[ni][nj]) {
                    next_water.push(Node(ni, nj));
                    visited[ni][nj] = true;
                }
            }
        }

        while (!next_water.empty()) {
            Node current = next_water.front();
            next_water.pop();
            m[current.r][current.c] = '.';
            water.push(current);
            for (int d = 0; d < 4; d++) {
                int ni = current.r + dx[d];
                int nj = current.c + dy[d];
                if (check(ni, nj)) continue;
                if (m[ni][nj] == '.') {
                    unite(current.r * C + current.c, ni * C + nj);
                }
            }
        }

        year++;
    }

    cout << year << endl;
    return 0;
}
