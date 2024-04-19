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

int dp[1000005],N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    fill(&dp[0], &dp[0] + 1000005, 1000005);

    dp[N] = 0;
    for (int i = N; i >= 2; i--) {
        if (i % 3 == 0) dp[i / 3] = min(dp[i] + 1, dp[i / 3]);
        if (i % 2 == 0)dp[i / 2] = min(dp[i] + 1, dp[i / 2]);
        dp[i - 1] = min(dp[i] + 1, dp[i - 1]);
    }

    cout << dp[1];
   
    return 0;
}

