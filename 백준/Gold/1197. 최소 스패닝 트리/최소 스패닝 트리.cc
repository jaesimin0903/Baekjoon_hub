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

tuple <int, int, int> graph[100001];

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
   
    

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int dis, v1, v2;

        cin >> v1 >> v2 >> dis;

        graph[i] = { dis,v1,v2 };
    }

    sort(graph, graph + E);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < E; i++) {
        int a, b, dis;
        tie(dis,a, b) = graph[i];
        //cout << is_diff_group(a, b) << "\n";
        if (!is_diff_group(a, b))continue;
        ans += dis;
        cnt++;
        if (cnt == V - 1) break;
    }
    cout << ans;

    return 0;


}