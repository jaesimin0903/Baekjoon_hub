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

int N, W;

ll dp[1010][40];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> N >> W;
    
    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;

        for (int j = 0; j <= W; j++) {
            if (n == 1) {
                dp[i][j] = dp[i - 1][j] + (j % 2 == 0 ? 1 : 0);
            }
            else {
                dp[i][j] = dp[i - 1][j] + (j % 2 == 1 ? 1 : 0);
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + (j % 2 == n - 1 ? 1 : 0));
            }
        }
    }

    ll max_num = 0;
    for (int i = 0; i <= W; i++) {
        max_num = max(max_num, dp[N][i]);
    }

    cout << max_num;

    return 0;
}

//1번에 있을때 
//dp[n][1][0]

//dp[n][2][1] = dp[n][1][0]
//dp[n][1][0] = dp[n][1]