#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
using namespace std;

int N, M,T;

int L;
//int maze[101][101] = { 0, };
vector<string> maze;
vector<int> ans;
bool visited[1001][1001] = { 0, };
int dis[1001][1001][2];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    queue<tuple<int,int, int>> q;
    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        maze.push_back(str);

        v.push_back(make_pair(0,0));
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '1') {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dis[i][j][0] = dis[i][j][1] = -1;
        }
    }

    
    int minn = 99999999;
    int ans = 0;

        
        q.push({ 0,0,0 });
        visited[0][0] = 1;
        dis[0][0][0] = dis[0][0][1] = 0;
        
        
        while (!q.empty()) {
            int y, x, broken;
            tie(y, x, broken) = q.front();
            q.pop();
            if (y == N - 1 && x == M - 1) {
                cout << dis[y][x][broken] + 1;
                return 0;
                
            }

            int nextdist = dis[y][x][broken] + 1;

            for (int j = 0; j < 4; j++) {
                int ny = y + dy[j];
                int nx = x + dx[j];

                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (maze[ny][nx] == '0' && dis[ny][nx][broken] == -1) {
                    dis[ny][nx][broken] = nextdist;
                    q.push({ ny,nx,broken });
                }
                if (!broken && maze[ny][nx] == '1' && dis[ny][nx][1] == -1) {
                    dis[ny][nx][1] = nextdist;
                    q.push({ ny,nx,1 });
                }

            }
        }

        cout << -1;
     


    return 0;
}
