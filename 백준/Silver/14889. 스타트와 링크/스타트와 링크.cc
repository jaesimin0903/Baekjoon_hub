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
#include<cstring>
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

int a[25][25],N,M, d, k, c,ret;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    // 1. 팀의 조합을 구하기 
    // 2. 조합별 점수 구하기
    // 3. 점수 차 최신화

    vector<int> per;

    for (int i = 0; i < N / 2; i++) {
        per.push_back(0);
        per.push_back(1);
    }

    sort(per.begin(), per.end());

    int ret = 99999999;

    do {
        vector<int> start, link;
        for (int i = 0; i < per.size(); i++) {
            if (per[i] == 0) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }

        int s_sum =0, l_sum = 0;
        for (int i = 0; i < start.size(); i++) {
            for (int j = 0; j < start.size(); j++) {
                s_sum += a[start[i]][start[j]];
                l_sum += a[link[i]][link[j]];
            }
        }

        ret = min(ret, abs(s_sum - l_sum));

    } while (next_permutation(per.begin(), per.end()));

    cout << ret;

    return 0;
}

