#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // 인접 리스트
    vector<bool> visited(n + 1, false);
    int ans = 0;

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2); // 인접 리스트에 간선 추가
        adj[n2].push_back(n1); // 양방향 간선 고려
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int s = q.front();
                q.pop();

                for (int neighbor : adj[s]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            ans++;
        }
    }

    cout << ans;

    return 0;
}
