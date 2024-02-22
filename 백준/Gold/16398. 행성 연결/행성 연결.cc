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
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long d;
            cin >> d;
            
            if (i == j) continue;
            graph->push_back({ d,i,j });
        }
    }

    sort(graph->begin(), graph->end());

    int cnt = 0;
    long long ans = 0;

    for (int i = 0; i < graph->size(); i++) {
        int a, b;
        long long d;
        tie(d,a, b) = graph->at(i);

        if (!is_diff_group(a, b))continue;

        cnt++;
        ans += d;

        if (cnt == N - 1)break;
    }
    
    cout << ans;


    return 0;


}