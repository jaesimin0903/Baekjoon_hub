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

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

char board[12][6];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }
    while (1) {
        // chain 
        bool visited[12][6] = { false, };
        bool flag = false;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] == '.')continue;
                if (visited[i][j])continue;

                char target;
                target = board[i][j];
                bool answer_flag = true;
                bool dir_cnt[4] = { 0, };

                int cnt = 1;
                vector<pair<int, int>> v;
                v.push_back({ i,j });
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = 1;
                while (!q.empty()) {
                    int y, x;
                    tie(y, x) = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int ny = y + dy[dir];
                        int nx = x + dx[dir];
                        if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6) continue;
                        if (visited[ny][nx] || target != board[ny][nx])continue;
                        q.push({ ny,nx });
                        v.push_back({ ny,nx });
                        cnt++;
                        visited[ny][nx] = 1;
                    }
                }

                if (cnt >= 4 && answer_flag) {
                    flag = true;
                    for (int h = 0; h < v.size(); h++) {
                        board[v[h].first][v[h].second] = '.';
                    }
                    v.clear();
                }
            }
        }
        
        if (!flag) {
            cout << answer;
            return 0;
        }
        else {
            answer++;
        }
        // 하강

        for (int i = 0; i < 6; i++) {
            char tmp[12]; // Use char array to match the board's type
            std::fill(tmp, tmp + 12, '.'); // Initialize all elements with '.'
            int idx = 11;
            for (int j = 11; j >= 0; j--) {
                if (board[j][i] != '.') {
                    tmp[idx--] = board[j][i]; // Assign non-empty blocks to new positions
                }
            }
            for (int j = 0; j < 12; j++) {
                board[j][i] = tmp[j]; // Update the board with the new positions
            }
        }

    }
    

    cout << answer;
    return 0;
}

