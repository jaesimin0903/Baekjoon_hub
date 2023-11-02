#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N;
    cin >> N;
    //nxn 1x1 -> nxn jump

    vector<vector<ll>>v(N, vector<ll>(N));
    vector<vector<ll>>dp(N, vector<ll>(N, 0));



    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < N; j++) {
            ll num;
            cin >> num;
            v[i][j] = num;
        }
    }
    int i = 0;
    int j = 0;
    dp[0][0] = 1;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            if (v[i][j] == 0) continue;

            if(v[i][j] != 0) {
                if (i + v[i][j] <= N - 1)dp[i + v[i][j]][j] +=  dp[i][j];
                if (j + v[i][j] <= N - 1)dp[i][j + v[i][j]] += dp[i][j] ;


            }
        }

    }

        
        
    

    cout << dp[N - 1][N - 1];

    return 0;
}
