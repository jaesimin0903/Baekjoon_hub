#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <deque>
#include <tuple>
#include <utility>
#include <map>
using namespace std;

typedef long long ll;

int N , Q, L,M;

ll dp[2000010];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    dp[999999] = 1;
    dp[1000000] = 0;
    dp[1000001] = 1;
    for(int i = 1000002;i<= 1000000 + abs(N);i++){
        dp[i] = (dp[i-1] + dp[i-2])%1000000000;
    }

    for(int i = 999998;i>=0;i-- ){
        if(dp[i+2] - dp[i+1] >= 0)
            dp[i] = (abs(-dp[i+1] + dp[i+2]) % 1000000000);
        else
            dp[i] = -(abs(-dp[i+1] + dp[i+2]) % 1000000000);
    }
    //2 -1 1 0 1
    if(dp[N+1000000] < 0) cout << -1;
    else if(dp[N+1000000] == 0) cout << 0;
    else cout << 1;
    cout << "\n" << abs(dp[N+1000000]);

    return 0;
}