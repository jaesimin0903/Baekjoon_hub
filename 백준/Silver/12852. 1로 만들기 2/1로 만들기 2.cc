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

int N, M;
int dp[1000005];
int pre[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> N;
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << dp[N] << '\n';
    int cur = N;
    while (1) {
        cout << cur << ' ';
        if (cur == 1) break;
        cur = pre[cur];
    }


    return 0;
}

