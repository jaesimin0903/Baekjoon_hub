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

int N, M;

vector<int> value;
vector<string> name;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string nm;
        int num;

        cin >> nm >> num;
        name.push_back(nm);
        value.push_back(num);
    }

    for (int i = 0; i < M; i++) {
        int power;
        cin >> power;

        bool isOkay = false;
        
        cout << name[lower_bound(value.begin(), value.end(), power) - value.begin()] << "\n";
    }

    
    return 0;
}

