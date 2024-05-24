#include <iostream>
using namespace std;

int n;
long long ans, dp[100001][5];
long long DP(int x, int idx) {
	if (x == 1) return 1;
	if (dp[x][idx]) return dp[x][idx];
	else if (idx == 0) {
		for (int i = 0; i < 5; i++)
			dp[x][idx] += DP(x - 1, i);
		return dp[x][idx] %= 100000007;
	}
	else if (idx == 1)
		return dp[x][idx] = (DP(x - 1, 0) + DP(x - 1, 2) + DP(x - 1, 3)) % 100000007;
	else if (idx == 2)
		return dp[x][idx] = (DP(x - 1, 0) + DP(x - 1, 1) + DP(x - 1, 3) + DP(x - 1, 4)) % 100000007;
	else if (idx == 3)
		return dp[x][idx] = (DP(x - 1, 0) + DP(x - 1, 1) + DP(x - 1, 2)) % 100000007;
	return dp[x][idx] = (DP(x - 1, 0) + DP(x - 1, 2)) % 100000007;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < 5; i++) ans += DP(n, i);
	cout << ans % 100000007;
	return 0;
}