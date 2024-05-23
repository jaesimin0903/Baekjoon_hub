#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m[2020][2020];
bool visited[2020][2020];
int parent[2020 * 2020];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int remaining_civs;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unite(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> v;

    for (int i = 0; i < 2020 * 2020; i++) {
        parent[i] = i;
    }
    int remaining_civs = K;

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < K; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        m[n2][n1] = 1;
        q.push({n2, n1, 0});
        visited[n2][n1] = true;
        v.push_back({n2, n1});
                for (int d = 0; d < 4; d++) {
                    int nny = n2 + dy[d];
                    int nnx = n1 + dx[d];
                    if (nny < 1 || nnx < 1 || nny > N || nnx > N) continue;
                    if (!visited[nny][nnx]) continue;
                    int pa = getParent(n2 * N + n1);
                    int pb = getParent(nny * N + nnx);
                    if (pa != pb) {
                        unite(pa, pb);
                        remaining_civs--;
                    }
                }
    }

    int year = 0;

    while (remaining_civs > 1 &&!q.empty()) {
        int y, x, s;
        tie(y, x, s) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 1 || nx < 1 || ny > N || nx > N) continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                m[ny][nx] = m[y][x] + 1;
                q.push({ny, nx, s + 1});
                unite(ny * N + nx, y * N + x);

                for (int d = 0; d < 4; d++) {
                    int nny = ny + dy[d];
                    int nnx = nx + dx[d];
                    if (nny < 1 || nnx < 1 || nny > N || nnx > N) continue;
                    if (!visited[nny][nnx]) continue;
                    int pa = getParent(ny * N + nx);
                    int pb = getParent(nny * N + nnx);
                    if (pa != pb) {
                        unite(pa, pb);
                        remaining_civs--;
                    }
                }
            } else {
                int pa = getParent(y * N + x);
                int pb = getParent(ny * N + nx);
                if (pa != pb) {
                    unite(pa, pb);
                    remaining_civs--;
                }
            }
        }

        if (remaining_civs == 1) {
            year = s + 1;
            break;
        }
    }

    cout << year << endl;
    return 0;
}