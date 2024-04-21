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

ll dp[50];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    cin >> M;

    ll answer  =1;

    dp[1] = 1;
    dp[2] = 2;
    for(int i= 3;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    int bef_num = 1;;
    dp[0] = 1;
    for(int i =0;i<M;i++){
        int n;
        cin >> n;
        answer *= dp[n-bef_num];
        bef_num = n+1;
    }

    cout << answer * (dp[N +1- bef_num]);
    //dp[1] = 1
    //dp[2] = 2
    //dp[3] = 3
    //dp[4] = 5
    //dp[5] = 8

    return 0;
}