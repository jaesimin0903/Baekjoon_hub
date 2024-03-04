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

int people[11] = { 0 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> people[i];
    }

    vector<int> ans;
    for (int i = N ; i > 0; i--) {
        if (ans.empty()) {
            ans.push_back(i);
        }
        else {
            int cnt = 0;
            for (int j = 0; j < ans.size(); j++) {
                if (people[i] == 0) {
                ans.insert(ans.begin(), i);
                break;
                }
                
                if (ans[j] > i) {
                    cnt++;
                    if (cnt == people[i]) {
                        ans.insert(ans.begin()+cnt, i);
                        break;
                    }
                }
                
            }
        }
    }

    for (auto val : ans) {
        cout << val << " ";
    }
    return 0;
}

