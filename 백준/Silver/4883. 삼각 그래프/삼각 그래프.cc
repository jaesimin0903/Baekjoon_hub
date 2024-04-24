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

int arr[100010][3];
int dp[100010][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    int num = 1;
    while (1) {
        cin >> N;

        if (N == 0) return 0;
        for (int i = 0; i < N; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        }

        dp[0][0] = 1000000;
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][1]+arr[0][2];

        for (int i = 1; i < N; i++) {
            dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]) + arr[i][0];
            dp[i][1] += min(dp[i - 1][0], min(dp[i - 1][1], min(dp[i - 1][2], dp[i][0]))) + arr[i][1];
            dp[i][2] += min(dp[i - 1][1], min(dp[i][1], dp[i - 1][2])) + arr[i][2];
            //cout << dp[i][0] << dp[i][1] << dp[i][2] << "\n";
        }

        cout << num << ". " << dp[N - 1][1] << "\n";
        num++;
        fill(&arr[0][0], &arr[0][0] + 100010 * 3, 0);
        fill(&dp[0][0], &dp[0][0] + 100010 * 3, 0);
    }
    

    return 0;
}
