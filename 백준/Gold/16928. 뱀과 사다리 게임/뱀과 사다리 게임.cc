#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<int, int> um;
bool visited[101]; // 방문 체크 배열

int main() {
    int N, M;
    cin >> N >> M;

    // 사다리와 뱀 정보 입력
    for (int i = 0; i < N + M; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        um[n1] = n2;
    }

    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    visited[1] = true; // 시작 위치 방문 체크
    int ans = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();

        // 목표 위치에 도달하면 종료
        if (cur == 100) {
            ans = count;
            break;
        }

        // 주사위를 굴려 1~6칸 이동
        for (int i = 1; i <= 6; i++) {
            int next = cur + i;
            if (next > 100) continue; // 100을 넘어가면 무시

            // 사다리나 뱀이 있으면 이동
            if (um.find(next) != um.end()) {
                next = um[next];
            }

            // 방문 체크
            if (!visited[next]) {
                visited[next] = true;
                q.push({ next, count + 1 });
            }
        }
    }

    cout << ans;
    return 0;
}
