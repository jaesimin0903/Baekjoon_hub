#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
typedef unsigned long long int ll;
int N;

string sum(string a, string b) {
	string ans = "";
	int num = 0;
	int carry = 0;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.size() < b.size()) {
		a += "0";
	}

	while (b.size() < a.size()) {
		b += "0";
	}

	for (int i = 0; i < a.size(); i++) {
		num = ((a[i] - '0') + (b[i] - '0') + carry) % 10;
		ans += to_string(num);
		carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
	}
	if (carry != 0) {
		ans += to_string(carry);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	string dp[10010];
	//fill(dp, dp + 10010, "0");

	dp[0] = "0";
	dp[1] = "1";
	for (int i = 2; i <= N; i++) {
		//cout << dp[i - 1] << " " << dp[i - 2] << "\n";
		dp[i] = sum(dp[i - 1] , dp[i - 2]);
	} 

	cout << dp[N];

	return 0;
}
