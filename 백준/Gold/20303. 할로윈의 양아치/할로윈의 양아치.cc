#include <iostream>
#include <vector>
#include <algorithm>  // min 함수 사용을 위해 추가
#include <unordered_set>
using namespace std;

int N, M, K;
int cost[30001];  // 각 인원의 사탕 수
pair<int, int> totalWithCandy[30001];  // 그룹의 인원 수와 그에 따른 총 사탕 수
int parent[30001];  // 유니온 파인드를 위한 부모 배열
int dp[30001];  // DP 테이블
bool visited[30001];  // 방문 확인
unordered_set<int> us;  // 유니온 파인드로 묶인 집합
vector<pair<int, int>> party;  // 각 그룹의 (인원 수, 사탕 수) 정보를 담은 벡터

// 부모를 찾는 함수
int getParent(int x) {
    if (x != parent[x]) {
        parent[x] = getParent(parent[x]);  // 경로 압축
    }
    return parent[x];
}

// 두 집합을 합치는 함수
void unite(int a, int b) {
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa != pb) {
        if (pa < pb) {
            us.insert(pa);
            parent[pb] = pa;
        }
        else {
            us.insert(pb);
            parent[pa] = pb;
        }
    }
}

int main() {
    cin >> N >> M >> K;  // N: 총 인원, M: 관계 수, K: 최대 인원 수

    for (int i = 1; i <= N; i++) {
        parent[i] = i;  // 유니온 파인드 초기화
    }

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];  // 각 인원의 사탕 수 입력
    }

    // 그룹 초기화 (각 그룹은 자기 자신으로 시작)
    for (int i = 1; i <= N; i++) {
        totalWithCandy[i] = { 1, cost[i] };  // (인원 1명, 해당 인원의 사탕 수)
    }

    // 관계 정보 입력 및 유니온 파인드 수행
    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        visited[n1] = true;
        visited[n2] = true;
        unite(n1, n2);
    }

    for(int i = 1;i<=N;i++){
        if(i != getParent(i)){
            int p = getParent(i);
            totalWithCandy[p].first += totalWithCandy[i].first;
            totalWithCandy[p].second += totalWithCandy[i].second;
        }
    }

    // // 유니온 파인드로 묶이지 않은 노드 처리
    // for (int i = 1; i <= N; i++) {
    //     if (!visited[i]) {
    //         us.insert(getParent(i));
    //     }
    // }

    // // 각 그룹 정보 저장
    // for (auto i : us) {
    //     party.push_back(totalWithCandy[i]);
    // }

    int answer = 0;
    //cout << us.size();
    // 배낭 문제 적용 (수정된 부분)
    for(int i = 1;i<=N;i++){
        if(i != getParent(i)) continue;
    
        int cnt = totalWithCandy[i].first;
        int candy = totalWithCandy[i].second;
        //cout << cnt << candy;
        for (int j = K - 1; j - cnt >= 0;j--) {
            dp[j] = max(dp[j], dp[j - cnt] + candy);
            answer = max(answer, dp[j]);
        }
    }

    // 최대 사탕 수 출력
    cout << answer << endl;

    return 0;
}
