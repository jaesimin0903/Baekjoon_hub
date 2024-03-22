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

//vector<tuple <long long, int, int>> graph[1000001];
//
//int V, E;
//
//vector<int> parent(100005, -1);

//int find(int x) {
//    if (parent[x] < 0) return x;
//    return parent[x] = find(parent[x]);
//}
//
//bool is_diff_group(int u, int v) {
//    u = find(u); v = find(v);
//    if (u == v) return 0;
//    if (parent[u] == parent[v])parent[u]--;
//    if (parent[u] < parent[v]) parent[v] = u;
//    else parent[u] = v;
//    return 1;
//}

int a[10][10],N,M, d, k, c,ret;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool visited[10][10];

vector<pair<int, int>> virus, wall;

void dfs(pair<int, int>p) {
    //cout << "dfs" << "\n";
    for (int i = 0; i < 4; i++) {
        int ny = p.first + dx[i];
        int nx = p.second + dy[i];
       // cout << ny << " " << nx << "\n";
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)continue;
        //cout << 1 << "\n";
        if (visited[ny][nx]) continue;
        //cout << 2 << "\n";
        if (a[ny][nx] == 1) continue;

            visited[ny][nx] = 1;
            dfs({ ny,nx });
        
    }
}

int go(int y, int x) {
    //cout << "go" << "\n";
    memset(visited, 0, sizeof(visited));
    for (pair<int, int> p : virus) {
        visited[p.first][p.second] = 1;
        dfs(p);
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0 && a[i][j] == 0) {
                //cout << i << " : " << j << "\n";
                count++;
            }
        }
    }

    return count;
}

#include<sstream>
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];

            if (a[i][j] == 2)virus.push_back({ i,j });
            if (a[i][j] == 0)wall.push_back({ i,j });
        }
    }

    int l = wall.size();

    for (int i = 0; i < l; i++) {
        for (int j = i+1; j < l; j++) {
            for (int k = j+1; k < l; k++) {
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;

                /*if (ret != max(ret, go(i, j))) {
                    for (int x = 0; x < N; x++) {
                        for (int y = 0; y < M; y++) {
                            cout << a[x][y] << " ";
                        }
                        cout << "\n";
                    }
                    cout << "\n";
                    for (int x = 0; x < N; x++) {
                        for (int y = 0; y < M; y++) {
                            cout << visited[x][y] << " ";
                        }
                        cout << "\n";
                    }
                }*/
                ret = max(ret, go(i, j));

                

                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
         }
    }

    cout << ret;

    return 0;
}

