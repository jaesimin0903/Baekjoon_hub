#include <iostream>
#include <vector>
using namespace std;

int N, M, num;

int parent[2000];

// find 연산 (경로 압축 적용)
int getParent(int x) {
    if (x != parent[x]) {
        parent[x] = getParent(parent[x]);
    }
    return parent[x];
}

// union 연산
void unite(int a, int b) {
    int pA = getParent(a);
    int pB = getParent(b);

    if (pA != pB) {
        parent[pB] = pA;
    }
}

int main() {
    cin >> N >> M;

    // 부모 배열 초기화 (자기 자신이 부모)
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    // 진실을 아는 사람들 입력
    cin >> num;
    vector<int> truthPeople(num);
    for (int i = 0; i < num; i++) {
        cin >> truthPeople[i];
        // 진실을 아는 사람을 0번 노드와 연결 (0번 노드는 진실 집합을 의미)
        unite(0, truthPeople[i]);
    }

    vector<vector<int>> part(M);

    // 각 파티 입력
    for (int i = 0; i < M; i++) {
        int size;
        cin >> size;
        vector<int> v(size);
        for (int j = 0; j < size; j++) {
            cin >> v[j];
        }
        part[i] = v;

        // 파티 참가자들을 같은 집합으로 묶음
        for (int j = 0; j < size - 1; j++) {
            unite(v[j], v[j + 1]);
        }
    }

    // 거짓말 할 수 있는 파티 수 계산
    int ans = 0;
    for (const auto& vv : part) {
        bool canLie = true;
        for (int i = 0; i < vv.size(); i++) {
            // 파티 참가자가 진실 집합에 속한 경우 거짓말을 할 수 없음
            if (getParent(vv[i]) == getParent(0)) {
                canLie = false;
                break;
            }
        }
        if (canLie) ans++;
    }

    // 결과 출력
    cout << ans << endl;

    return 0;
}
