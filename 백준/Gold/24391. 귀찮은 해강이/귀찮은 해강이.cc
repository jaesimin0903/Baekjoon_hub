#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;
int parent[100001];

// 경로 압축을 사용하는 부모 찾기 함수
int getParent(int x) {
    if (x != parent[x]) {
        parent[x] = getParent(parent[x]); // 경로 압축
    }
    return parent[x];
}

// 두 컴포넌트를 병합하는 연산
void unite(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa != pb) {
        parent[pb] = pa; // 루트 기준 병합
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 각 노드의 부모를 자기 자신으로 초기화
    for (int i = 1; i <= N; i++) parent[i] = i;

    // M개의 간선 처리
    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        unite(n1, n2);
    }

    int ans = 0;
    int cur;
    
    // 시퀀스의 첫 번째 노드를 읽음
    cin >> cur;
    
    // 시퀀스를 처리하고 컴포넌트 변경 횟수를 카운트
    for (int i = 1; i < N; i++) {
        int next;
        cin >> next;
        if (getParent(cur) != getParent(next)) ans++;
        cur = next;
    }

    // // 디버깅을 위한 부모 배열 출력
    // for (int i = 1; i <= N; i++) cout << parent[i] << " ";
    // cout << "\n";

    // 결과 출력
    cout << ans;
    return 0;
}
