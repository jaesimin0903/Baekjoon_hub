#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include<stack>
#include<cmath>
using namespace std;


int main() {
	int n;
	int dp[16]={0,};
	vector<pair<int,int>>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		v.push_back({ num1,num2 });
	}
	//4-3 <=1

	for (int i = n-1; i >=0; i--) {
		if (i + v[i].first > n) {
			dp[i] = dp[i +1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + v[i].first] + v[i].second);
		}
	}

	cout << dp[0];
	return 0;
}

