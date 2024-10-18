#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

ll N, M;

int main() {
    cin >> N >> M;

    // N개의 앱 A~AN 활성화
    // 각각 mi 바이트만큼의 메모리 사용
    // 앱 Ai 비활성한 후 추가적 비용 ci

    ll memory[200]; // 각 앱이 사용하는 메모리
    ll cost[200];   // 각 앱을 비활성화할 때 드는 비용
    for (int i = 1; i <= N; i++) {
        cin >> memory[i];
    }
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    // dp[i][j]는 i개의 앱을 고려해서 j만큼의 메모리를 확보할 때 최소 비용
    ll dp[210][10001]; // 최대 메모리와 비용을 고려한 dp 배열
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0); // 큰 값으로 초기화
    dp[0][0] = 0; // 초기 상태: 0 비용으로 0 메모리 확보

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] +  memory[i]);
            }
            // 현재 앱을 비활성화하지 않는 경우
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            // 현재 앱을 비활성화하는 경우
        }
    }

    // 최소한 M 이상의 메모리를 확보할 수 있는 최소 비용 찾기
    ll ans = 1e9;
    for (int j = 0; j <= sum; j++) {
        if (dp[N][j] >= M) {
            cout << j;
            break;
        }
    }

    //cout << ans << endl;

    return 0;
}
