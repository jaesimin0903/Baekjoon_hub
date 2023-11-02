#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int T;
	cin >> T;
	int dp[50001] = { 0, };
	dp[1] = 1;

	for (int i = 2; i < 50001; i++) {
		int minn = 9999999;
		for (int j = 1; j * j <= i; j++) {
			minn = min(minn, dp[i - j * j]);
		}
		dp[i] = minn + 1;

	}

	

	cout << dp[T];
	return 0;
}