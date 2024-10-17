#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int parent[210];
int graph[210][210];

int getParent(int x) {
    if (x != parent[x]) {
        return getParent(parent[x]);
    }
    return x;
}

void unite(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa != pb) {
        parent[pb] = pa;
    }
}

int main() {
    
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 1) {
                unite(i, j);
            }
        }
    }

    vector<int> root;
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        root.push_back(n);
    }

    int target = getParent(root[0]);
    for (int i = 1; i < M; i++) {
        if (target != getParent(root[i])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
