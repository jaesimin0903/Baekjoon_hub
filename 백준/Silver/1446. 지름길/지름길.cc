#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> dp(D+1, 0);
    for (int i = 1; i <= D; i++) dp[i] = i;  // 초기화

    vector<vector<int>> shortcuts;
    for (int i = 0; i < N; i++) {
        int start, end, length;
        cin >> start >> end >> length;
        if (end <= D) {  // D를 넘지 않는 경우만 고려
            shortcuts.push_back({start, end, length});
        }
    }

    for (int i = 0; i <= D; i++) {
        if (i > 0) dp[i] = min(dp[i], dp[i-1] + 1);  // 일반 도로 이용
        for (auto& sc : shortcuts) {
            int start = sc[0], end = sc[1], length = sc[2];
            if (start <= i && i == end) {
                dp[end] = min(dp[end], dp[start] + length);
            }
        }
    }
    cout << dp[D] << endl;
    return 0;
}
