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

int N, T;

ll dp[1000010][40];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    //dp[1] = 1 dp[1][1] = 1, dp[1][2] = 0, dp[1][3] = 0
    //dp[2] = 11 2 ,2  dp[2][1] = 1, dp[2][2] = 1, dp[2][3] = 0
    //dp[3] = 111 12 21 3, 4 dp[3][1] = 2 dp[3][2] = 1 dp[3][3] = 1
    //dp[4] = 1111 121 211 31 112 22 13, 7 dp[4][1] = 4, dp[4][2] = 2, dp[4][3] = 1
    //dp[5] = 11111 1211 1121 2111 131 311 221 / 1112 122 212 32 / 113 23  dp[5][1] = 7, dp[5][2] = 

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[1][3] = 0;
    dp[2][1] = 1;
    dp[2][2] = 1;
    dp[2][3] = 0;
    dp[3][1] = 2;
    dp[3][2] = 1;
    dp[3][3] = 1;

    for (int i = 4; i <= 1000000; i++) {
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][2] + dp[i - 2][3]) % 1000000009;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3]) % 1000000009;
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << (dp[N][1] + dp[N][2] + dp[N][3])%1000000009 << "\n";

    }

    return 0;
}

//1번에 있을때 
//dp[n][1][0]

//dp[n][2][1] = dp[n][1][0]
//dp[n][1][0] = dp[n][1]