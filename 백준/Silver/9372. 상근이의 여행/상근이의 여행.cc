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

vector<tuple <int, int, int>> graph[100001];

int V, E;

vector<int> parent(10005, -1);

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




int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int city, plane;
        cin >> city >> plane;

        for (int j = 0; j < plane; j++) {
            int dis, a, b;
            cin >> a >> b;
            dis = 1;
            graph->push_back({ a,b,1 });
            graph->push_back({ b,a,1 });
        }

        sort(graph->begin(), graph->end());
        int cnt = 0;
        int ans = 0;
        for (int j = 0; j < graph->size(); j++) {
            int dis, a, b;
            tie( a, b,dis) = graph->at(j);
            if (!is_diff_group(a, b))continue;
            //cout<< cnt << " " << city << " " << a << "--" << b << "\n";
            ans += dis;
            cnt++;
            if (cnt == city-1) break;
        }
        cout << ans << "\n";
        graph->clear();
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = -1;
        }
    }



    return 0;


}