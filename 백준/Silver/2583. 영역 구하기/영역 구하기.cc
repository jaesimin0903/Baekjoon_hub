#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
#include <cmath>
using namespace std;

int N, M, K;

int map[101][101];
bool visited[101][101];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; j++) {
            for (int k = x1; k < x2; k++) {
                map[j][k] = 1;
            }
        }
    }

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }*/
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                int size = 0;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    size++;

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
                        if (visited[ny][nx])continue;
                        if (map[ny][nx] != 0)continue;
                        q.push(make_pair(ny, nx));
                        visited[ny][nx] = 1;
                    }
                }
                ans.push_back(size);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto val : ans) {
        cout << val << " ";
    }

    return 0;
}
