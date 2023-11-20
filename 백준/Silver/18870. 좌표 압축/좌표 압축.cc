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


int LCS(string s1, string s2,string s3) {
	int s1L = s1.length();
	int s2L = s2.length();
	int s3L = s3.length();

	//vector<vector<int>> dp(s1L+1, vector<int>(s2L+1, 0));
	//vector<vector<int>> a(s1L + 1, vector<int>(s2L + 1, 0));

	vector<vector<vector<int>>> dp(s1L + 1, vector<vector<int>>(s2L + 1, vector<int>(s3L + 1, 0)));
	

	//for (int i = 1; i <= s1L; i++) {
	//	for (int j = 1; j <= s2L; j++) {
	//		if (s1[i-1] == s2[j-1]) {
	//			dp[i][j] = dp[i - 1][j - 1]+1;
	//			a[i][j] = 1;
	//		}
	//		else {
	//			dp[i][j] = max(dp[i - 1][j],dp[i][j-1]);
	//			if (dp[i - 1][j] > dp[i][j - 1]) {
	//				a[i][j] = 2;
	//			}
	//			else {
	//				a[i][j] = 3;
	//			}
	//		}
	//	}
	//}

	for (int i = 1; i <= s1L; i++) {
		for (int j = 1; j <= s2L; j++) {
			for (int k = 1; k <= s3L; k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
			}
		}
	}

	//getLCS(a, s1L, s2L, s2);
	//string rans = "";
	//for (int i = ans.size() - 1; i >= 0; i--) {
	//	rans += ans[i];
	//}
	//ans = rans;

	return dp[s1L ][s2L ][s3L];
}

#include <unordered_map>
int main() {
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	vector<int> copied = v;

	sort(copied.begin(), copied.end());

	int t = -1;
	int idx = 0;
	int cur = 0;


	unordered_map<int, int> ans;
	while (idx < N) {

		if (cur != copied[idx]) {
			t++;
			ans[copied[idx]] = t;
			cur = copied[idx];
			idx++;
			
		}
		else {
			ans[copied[idx]] = t;
			cur = copied[idx];
			idx++;
		}
	}

	for (int i = 0; i < N; i++) {
		v[i] = ans[v[i]];
	}

	for (int i = 0; i < N; i++) {
		cout << v[i] << " ";
	}

	return 0;
}
