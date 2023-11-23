#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int choose[10];


int num[1001];
int dp[1001];
int main (){
    cin >> N ;

    for(int i = 1;i<=N;i++){
        cin >> num[i];
    }
    int ans = 0;
    for(int i = 1;i<=N;i++){
        dp[i] = 1;
        for(int j = i-1;j>=1;j--){
            if(num[i] > num[j]){
                dp[i] = max(dp[i], dp[j] +1);
            }
        }
        ans = max(dp[i], ans);
    }

    // for(int i = 0;i<=N;i++){
    //     for(int j =0;j<=N;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout <<"\n";
    // }

    cout << ans;
    return 0;
}