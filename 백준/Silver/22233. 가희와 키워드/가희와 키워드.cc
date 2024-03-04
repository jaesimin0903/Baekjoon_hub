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
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        s.insert(str);
    }

    for (int i = 0; i < M; i++) {
        string str;
        cin >> str;
        stringstream ss(str);
        string item;
        vector<string> res;
        while (getline(ss, item, ',')) {
            res.push_back(item);
        }

        for (const auto& v : res) {
            if (s.find(v) != s.end()) {
                s.erase(v);
            }
        }

        cout << s.size() << "\n";
    }


    
    return 0;
}

