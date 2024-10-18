#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> degree;
vector<vector<int>> v;
vector<int> ans;

bool topology_sort() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) q.push(i);
    }

    for (int i = 1; i <= N; i++) {
        if (q.empty()) {
            cout << 0;
            return false;
        }

        int x = q.front();
        q.pop();
        ans.push_back(x);

        for (int j = 0; j < v[x].size(); j++) {
            int y = v[x][j];
            if (--degree[y] == 0) q.push(y);
        }
    }
    return true;
}

int main() {
    cin >> N >> M;

    degree.resize(N + 1, 0); // 동적 배열 할당
    v.resize(N + 1); // 동적 벡터 할당

    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        int fn;
        cin >> fn;
        for (int j = 0; j < n - 1; j++) {
            int num;
            cin >> num;
            degree[num]++; // 진입 차수 증가
            v[fn].push_back(num); // 간선 추가
            fn = num; // 다음 노드로 업데이트
        }
    }

    if (topology_sort()) {
        for (auto v : ans) cout << v << "\n";
    }

    return 0;
}
