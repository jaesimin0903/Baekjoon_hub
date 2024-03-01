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

int arr[10005] = { 0 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    int total = 0;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    cin >> M;
    
    int left, right;
    left = M / N;
    right = *max_element(arr, arr + N);
    if (total <= M) {
        cout << right;
        return 0;
    }
    while (left < right - 1) {
        int mid = (left + right) / 2;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] < mid) {
                sum += arr[i];
            }
            else {
                sum += mid;
            }
        }
        if (sum <= M) left = mid;
        else right = mid;
    }

    cout << left;

    //121, 1 11 -19, -29
    // -48 + 12 = -36
    //520 - 36 = 484

    //90, 20 10 50 50 -10
    //320 120  = 440
    
    return 0;
}

