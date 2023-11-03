#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

#define MAX 1500001
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    //돌이 1열
    //마지막 돌틈사이에 산삼
    //점프 다음돌 1, 큰점프 2, 매우큰점프 3(한번만)
    //점프를 하는데 필요한 최소에너지

    vector<pair<int, int>> v(N+1, { 0,0});
    
    for (int i = 1; i < N; i++) {
        int small, big;
        cin >> small >> big;

        v[i].first = small;
        v[i].second = big;
    }

    int K;
    cin >> K;
    int minn = 99999999;

    for (int attempt = 0; attempt <= N; attempt++) {
        int att= 1;
        vector<int> dp(N + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            if (attempt == i) {
                if (i + 3 < N && dp[i + 3] != 0) {
                    dp[i + 3] = min(dp[i + 3], dp[i] + K);

                    att = 0;
                }
                else if (i + 3 < N) {
                        dp[i + 3] = dp[i] + K;

                        att = 0;
                }
                else if(i+3 == N && dp[N] !=0) {
                    dp[N] = min(dp[N], dp[i] + K);
                    att = 0;
                }
                else if (i + 3 == N) {
                    dp[N] = dp[i] + K;
                    att = 0;
                }
            }
            if (i + 1 < N && dp[i + 1] != 0) dp[i + 1] = min(dp[i + 1], dp[i] + v[i].first);
            else if (i + 1 < N) dp[i + 1] = dp[i] + v[i].first;
            else if(i+1==N && dp[N]!=0) dp[N] =min(dp[N], dp[i] + v[i].first);
            else if(i+1==N) dp[N] = dp[i] + v[i].first;
            if (i + 2 < N && dp[i + 2] != 0) dp[i + 2] = min(dp[i + 2], dp[i] + v[i].second);
            else if (i + 2 < N) dp[i + 2] = dp[i] + v[i].second;
            else if (i + 2 == N && dp[N] != 0)  dp[N] = min(dp[N], dp[i] + v[i].second);
            else if (i + 2 == N)dp[N] = dp[i] + v[i].second;
        }
        minn = min(minn, dp[N]);
    }
    cout << minn;
    
    return 0;
}
