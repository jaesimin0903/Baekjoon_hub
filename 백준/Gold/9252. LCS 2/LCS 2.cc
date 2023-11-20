#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

queue<pair<int, int>> q;

int N, M,H;

string ans = "";

string getLCS(int str[1001][1001], int i, int j, string s1) {
	if (str[i][j] == 1) {
		ans += s1[j-1];
		getLCS(str, i - 1, j - 1, s1);
	}
	else if (str[i][j]==2) {
		getLCS(str, i - 1, j, s1);
	}
	else if (str[i][j] == 3) {
		getLCS(str, i, j - 1, s1);
	}
	return ans;

}
int LCS(string s1, string s2) {
	int s1L = s1.length();
	int s2L = s2.length();

	//vector<vector<int>> dp(s1L+1, vector<int>(s2L+1, 0));
	//vector<vector<int>> a(s1L + 1, vector<int>(s2L + 1, 0));

	int dp[1000 + 1][1000 + 1];
	int a[1000 + 1][1000 + 1];

	for (int i = 1; i <= s1L; i++) {
		for (int j = 1; j <= s2L; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1]+1;
				a[i][j] = 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j],dp[i][j-1]);
				if (dp[i - 1][j] > dp[i][j - 1]) {
					a[i][j] = 2;
				}
				else {
					a[i][j] = 3;
				}
			}
		}
	}

	getLCS(a, s1L, s2L, s2);
	string rans = "";
	for (int i = ans.size() - 1; i >= 0; i--) {
		rans += ans[i];
	}
	ans = rans;

	return dp[s1L ][s2L ];
}


int main() {
	//cin >> N >> L >> R;

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	cout << LCS(str1, str2)<<"\n";
	if (ans != "") {
		cout << ans;
	}

	return 0;
}
