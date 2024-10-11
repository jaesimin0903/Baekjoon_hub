#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int dp[100010][3] = { 0 };

    dp[0][0] = dp[0][1] = dp[0][2] = 1;

    for (int i = 1; i < N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }

    int ans = (dp[N-1][0] + dp[N-1][1] + dp[N-1][2]) % 9901;
    cout << ans << endl;

    return 0;
}

