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

string A, B;
int ans = 0;
void dfs(string aa, string bb) {
    //cout << str << "\n";

    if (aa == bb) {
        cout << 1;
        exit(0);
    }

    if (aa.length() > bb.length()) {
        return;
    }

    if (bb[bb.length() - 1] == 'A') {
        string tmp = bb;
        tmp.erase(tmp.length() - 1);

        dfs(aa, tmp);
    }

    if (bb[0] == 'B') {
        string tmp = bb;
        reverse(tmp.begin(), tmp.end());
        tmp.erase(tmp.length() - 1);
        dfs(aa, tmp);
    }
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> A >> B;


    dfs(A, B);
    cout << 0;
    
    return 0;
}

