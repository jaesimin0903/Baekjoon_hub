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
#include <unordered_map>
#include<cstring>
#include<iomanip>
using namespace std;

typedef long long ll;

typedef long long ll;
typedef pair<int, int> pii;  // Pair to store the vertex and weight

const ll INF = LLONG_MAX;  // Use maximum long long as infinity
int N, M;
vector<vector<pii>> graph;

void dijkstra(int start) {
    vector<ll> dist(N + 1, INF);
    vector<bool> visited(N + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize the start node
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }
    cout << dist[N];
    // Output the distances for verification
    //for (int i = 1; i <= N; i++) {
    //    if (dist[i] == INF) cout << "INF ";
    //    else cout << dist[i] << " ";
    //}
    //cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    graph.resize(N + 1);

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });  // If the graph is undirected
    }

    dijkstra(1);  // Assuming the start node is 1

    return 0;
}

//int N, K,M;
//map<int, vector<pair<int,int>>> v;
//bool visited[50010];
//ll answer = 50000 * 1000;
//ll INF = 50000 * 1000;
//int dp[50010];
//
//int getSmallIndex(int s) {
//    int min = INF;
//    int index = 0;
//    for (int i = 0; i < v[s].size(); i++) {
//        if (dp[v[s][i].first] < min && !visited[v[s][i].first]) {
//            min = dp[v[s][i].first];
//            index = i;
//        }
//    }
//    return index;
//}
//
//void dijkstra(int s) {
//    for (int i = 0; i < v[s].size(); i++) {
//        dp[v[s][i].first] = v[s][i].second;
//    }
//    visited[s] = true;
//    for (int i = 0; i < v[s].size()-2; i++) {
//        int current = getSmallIndex(v[])
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    cin >> N >> M;
//
//    while (M--) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        v[a].push_back({ b,c });
//        v[b].push_back({ a,c });
//    }
//
//    
//    cout << answer;
//
//    return 0;
//}
