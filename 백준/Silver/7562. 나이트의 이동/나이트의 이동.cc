#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
using namespace std;

int N, M,T;

int L;

struct Node {
    int y, x, a;

    Node() : y(0), x(0), a(0) {

    }
};

int main() {
    
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> L;

        int s_x, s_y, t_x, t_y;

        cin >> s_x >> s_y >> t_x >> t_y;

        int dx[8] = { -2,-2,-1, -1, 1,1,2, 2 };
        int dy[8] = { 1,-1,2, -2, 2,-2,1, -1 };

        vector<vector<bool>> visited(L, vector<bool>(L, false));

        queue<Node> q;

        int ans = 0;

        Node n;

        n.y = s_y;
        n.x = s_x;
        n.a = ans;

        q.push(n);

        while (!q.empty()) {
            int y = q.front().y;
            int x = q.front().x;
            int aa = q.front().a;

            q.pop();
            //cout << y << " " << x << " " << aa << "\n";
            if (visited[y][x]) {
                continue;
            }

            if (y == t_y && x == t_x) {
                cout << aa << "\n";
                break;
            }

            visited[y][x] = true;

            for (int j = 0; j < 8; j++) {
                if (y + dy[j] >= L || y + dy[j] < 0 || x + dx[j] >= L || x + dx[j] < 0) {
                    continue;
                }

                if (visited[y + dy[j]][x + dx[j]]) {
                    continue;
                }
                Node nn;
                nn.y = y + dy[j];
                nn.x = x + dx[j];
                nn.a = aa + 1;
                q.push(nn);
            }
        }
    }



    return 0;
}
