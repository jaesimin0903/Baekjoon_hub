#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include<cstring>
using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	//11726
	int n;
	cin >> n;
	ll dp[1001];
	ll count = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 1001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
		//cout << dp[i] << endl;
	}
	cout << dp[n];

    return 0;
}

