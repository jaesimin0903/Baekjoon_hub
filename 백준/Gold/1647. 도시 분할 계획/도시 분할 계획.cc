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

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;//house, road
    cin >> N >> M;

    int max_dis = 0;
    for (int i = 0; i <M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph->push_back({ c,a,b });
    }

    sort(graph->begin(), graph->end());

    int cnt = 0;
    long long ans = 0;

    for (int i = 0; i < graph->size(); i++) {
        int a, b;
        long long d;
        tie(d,a, b) = graph->at(i);

        if (!is_diff_group(a, b))continue;
        if (max_dis < d) max_dis = d;

        cnt++;
        ans += d;

        if (cnt == N - 1)break;
    }
    
    cout << ans - max_dis;


    return 0;


}