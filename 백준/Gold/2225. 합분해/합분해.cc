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
    cin >> N >> K;
 
    long long dp[201][201] = { 0 };

    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }

    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int i = 0; i <= n; i++) {
                dp[k][n] = dp[k][n] + dp[k - 1][i];
            }
            dp[k][n] %= 1000000000;
        }
    }

    cout << dp[K][N];

    return 0;


}

