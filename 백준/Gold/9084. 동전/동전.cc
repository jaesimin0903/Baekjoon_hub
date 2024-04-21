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

int N , Q, L,M,T;

ll dp[2000010];
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T--){
        fill(&dp[0], &dp[0] + 2000010, 0);
        cin >> N;
        vector<int> v;
        for(int i =0;i<N;i++){
            int n; cin >> n;
            v.push_back(n);
        }
        cin >> M;
        dp[0] = 1;
        for(int i= 0;i<N;i++){
            for(int j = v[i]; j <= M;j++){
                dp[j] += dp[j-v[i]];
            }
        }

        cout << dp[M]<<"\n";
        
    }


    return 0;
}