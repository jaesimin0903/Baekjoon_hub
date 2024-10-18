#include <iostream>
#include <vector>

using namespace std;

// 부모 배열 초기화
vector<int> parent;

// find 함수: 경로 압축을 사용하여 집합의 루트 찾기
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

// union 함수: 두 집합을 병합
void union_sets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    if (rootA != rootB) {
        parent[rootA] = rootB;
    }
}

// 사이클 판정 함수
bool hasCycle(pair<int, int>& edge) {
    int u = edge.first;
    int v = edge.second;

    // 두 노드가 같은 집합에 속해있다면 사이클이 존재
    if (find(u) == find(v)) {
        return true;
    }
    // 그렇지 않다면 두 집합을 병합
    union_sets(u, v);
    return false;
}

int main() {
    int n, m; // n: 노드 수, m: 간선 수
    cin >> n >> m;

    parent.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;  // 각 노드의 부모를 자기 자신으로 초기화
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({ u, v });

        // 사이클 판정
        if (hasCycle(edges.back())) {
            cout << i + 1;  // 최초 사이클이 발생한 간선의 번호 출력
            return 0;
        }
    }

    cout << 0;  // 사이클이 없는 경우 0 출력
    return 0;
}
