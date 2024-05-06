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
#include <string>
#include <sstream>
using namespace std;

typedef long long ll;

int N , Q, L,M,T;
int rest = 1000000;
ll dp[2000010];
ll arr[2000010];
ll updp[2000010];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    dp[0]= 1;

    for(int i =0;i<N;i++){
        cin >> arr[i];
    }
    ll ans = 0;
    for(int i = 0;i<N;i++){
        dp[i] = 1;
        for(int j =0;j<i;j++){
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for(int i = N-1;i>=0;i--){
        updp[i] = 1;
        for(int j = N-1;j>i;j--){
            if(arr[i] > arr[j]) updp[i] = max(updp[i], updp[j] + 1);
        }
    }

    //1 1 2 2 3 3
    //1 1 2 1 2 1 
    for(int i =0;i<N;i++){
        ans = max(ans, dp[i]+updp[i] -1);
        //cout << dp[i] << " ";
    }
    //cout << "\n";

    for(int i = 0;i<N;i++){
        //cout << updp[i] << " ";
    }
    //cout << "\n";

    cout << ans;
    return 0;
}