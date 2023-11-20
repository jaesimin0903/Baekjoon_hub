#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

queue<pair<int, int>> q;

int N, M,H;

int LCS(string s1, string s2) {
	int s1L = s1.length();
	int s2L = s2.length();

	vector<vector<int>> dp(s1L+1, vector<int>(s2L+1, 0));

	for (int i = 1; i <= s1L; i++) {
		for (int j = 1; j <= s2L; j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1]+1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j],dp[i][j-1]);
			}
		}
	}


	return dp[s1L ][s2L ];
}


int main() {
	//cin >> N >> L >> R;

	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	cout << LCS(str1, str2);

	return 0;
}
