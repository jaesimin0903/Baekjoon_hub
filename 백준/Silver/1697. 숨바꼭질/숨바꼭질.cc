#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;
    bool visited[100001] = { false, };
    q.push({ n, 0 });
    visited[n] = true;

    while (!q.empty()) {
        int location = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (location == m) {
            cout << cnt;
            break;
        }

        // 위치를 큐에 추가하기 전에 방문 여부를 확인
        if (location + 1 < 100001 && !visited[location + 1]) {
            visited[location + 1] = true;
            q.push({ location + 1, cnt + 1 });
        }
        if (location * 2 < 100001 && !visited[location * 2]) {
            visited[location * 2] = true;
            q.push({ location * 2, cnt + 1 });
        }
        if (location - 1 >= 0 && !visited[location - 1]) {
            visited[location - 1] = true;
            q.push({ location - 1, cnt + 1 });
        }
    }
    return 0;
}
