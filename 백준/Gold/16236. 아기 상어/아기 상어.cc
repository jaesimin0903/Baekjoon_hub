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
#include <map>
#include <unordered_set>
#include<cstring>
using namespace std;

int board[21][21];
int eat = 0;
int ssize = 2;
int N;
int ans = 0;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int cur_y, cur_x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                cur_x = j; cur_y = i;
            }
        }
    }
    while (1) {
        //탐색 bfs
        queue<tuple<int,int, int>>q;
        q.push({ cur_y,cur_x ,0});
        bool visited[21][21];
        fill(&visited[0][0], &visited[0][0] + 21 * 21, false);
        visited[cur_y][cur_x] = 1;
        bool is_ok = false;
        vector<tuple<int, int, int>>v;
        while (!q.empty()) {
            int y, x,d;
            tie(y, x,d) = q.front();
            q.pop();
            //cout << y << " " << x << "\n";

            if (board[y][x] < ssize && board[y][x] != 0 && (cur_y != y || cur_x != x)) {

                v.push_back({ y,x,d });

                is_ok = true;

            }


            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if (ssize < board[ny][nx])continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = 1;
                q.push({ ny,nx,d+1 });
            }
        }


        //있따? 먹기 -> 다시 bfs
        if (is_ok && !v.empty()) {
            sort(v.begin(), v.end(), [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
                if (std::get<2>(a) != std::get<2>(b)) // 3번째 원소를 비교
                    return std::get<2>(a) < std::get<2>(b);
                if (std::get<0>(a) != std::get<0>(b)) // 1번째 원소를 비교
                    return std::get<0>(a) < std::get<0>(b);
                return std::get<1>(a) < std::get<1>(b); // 2번째 원소를 비교
                });

            board[cur_y][cur_x] = 0;
            board[get<0>(v[0])][get<1>(v[0])] = 9;
            ans += get<2>(v[0]);
            
            cur_y = get<0>(v[0]), cur_x = get<1>(v[0]);

            fill(&visited[0][0], &visited[0][0] + 21*21, false);
            eat++;
            if (ssize == eat) {
                ssize++;
                eat = 0;
            }
            v.clear();
        }
        //없다? 엄마 break
        else {
            break;
        }
    }
    cout << ans;
    return 0;
}

