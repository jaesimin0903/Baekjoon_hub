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

int N,K;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int dp[10001][10];

    
    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; i++) {
        dp[i][0] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][0] == 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 10007;
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[N][i];
    }
    cout << ans % 10007;


    return 0;


}