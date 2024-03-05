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

int N, M;

unordered_set<string>s;

#include<sstream>
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char c;
    cin >> N >> c;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }

    if (c == 'Y') {
        cout << s.size();
    }
    else if (c == 'F') {
        cout << s.size() / 2;
    }
    else {
        cout << s.size() / 3;
    }

    
    return 0;
}

