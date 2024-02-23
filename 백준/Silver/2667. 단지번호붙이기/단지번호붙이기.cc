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

vector<tuple <long long, int, int>> graph[1000001];

int V, E;

vector<int> parent(100005, -1);

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return 0;
    if (parent[u] == parent[v])parent[u]--;
    if (parent[u] < parent[v]) parent[v] = u;
    else parent[u] = v;
    return 1;
}

int N;
vector<string>map;
bool visited[26][26];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        map.push_back(str);
    }

    vector<int> ans;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            if (visited[i][j])continue;
            if (map[i][j] != '1')continue;
            int cnt = 0;
            queue<pair<int, int>>q;
            q.push({ i,j });
            visited[i][j] = 1;
            cnt++;
            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (visited[ny][nx] || ny < 0 || nx < 0 || nx >= N || ny >= N)continue;
                    if (map[ny][nx] != '1')continue;
                    q.push({ ny,nx });
                    visited[ny][nx] = 1;
                    cnt++;
                }
            }

            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto v : ans) {
        cout << v << "\n";
    }

    return 0;


}