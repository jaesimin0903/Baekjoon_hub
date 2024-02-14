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

int N, S;


bool mask[25];
int ans = 0;
string map[5];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;

    for (int i = 0; i < 5; i++) {
        cin >> map[i];
    }

    fill(mask + 7, mask + 25, true);
    do {
        queue<pair<int, int>> q;

        int dasom = 0, adj = 0;
        bool isp7[5][5] = {}, vis[5][5] = {};
        for (int i = 0; i < 25; i++) {
            if (!mask[i]) {
                int x = i / 5, y = i % 5;
                isp7[x][y] = true;
                if (q.empty()) {
                    q.push({ x,y });
                    vis[x][y] = true;
                }
            }
        }
        while (!q.empty()) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            adj++;
            dasom += map[x][y] == 'S';
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp7[nx][ny])
                    continue;
                q.push({ nx, ny });
                vis[nx][ny] = true;
            }
        }
        ans += (adj >= 7 && dasom >= 4);
    } while (next_permutation(mask, mask + 25));

    cout << ans;

    return 0;


}