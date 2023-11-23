#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

long long N, M;
int choose[10];


int num[1001];

int main (){
    int T;
    cin >> T;
    for(int t = 0;t<T;t++){
        cin >> N ;
        int sticker[2][N+1];
        int dp[2][N+1];

        for(int i =0 ;i<2;i++){
            for(int j = 0;j<N;j++){
                cin >> sticker[i][j];
            }
        }

        dp[0][0] = sticker[0][0];
        dp[1][0] = sticker[1][0];
        dp[0][1] = dp[1][0] + sticker[0][1];
        dp[1][1] = dp[0][0] + sticker[1][1];
        for(int i = 2;i<N;i++){
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1],dp[0][i-2]);
        }
        cout << max(dp[0][N-1], dp[1][N-1])<<"\n";
    }
    

    return 0;
}