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
ll dp[1000005];
int pre[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> N;
    
    dp[1] = 1;
    dp[2] = 1;
    //1001 1010 1000
    //10010 10101 10100 10001 10000
    //100101 100100 101010 101001 101000 100010 100000 100001
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N];
    return 0;
}

