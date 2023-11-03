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

    vector<pair<int, int>> v(MAX, { 0, 0});
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int num1, num2;
        cin >> num1 >> num2;
        v[i] = { num1,num2 };
    
    }
    
    vector<int> dp(MAX, 0);
    for (int i = 1; i <= N+1; i++) {
        ans = max(ans, dp[i]);
        if (i + v[i].first <= N+1)dp[i+v[i].first]= max(dp[i + v[i].first], ans+ v[i].second);
    }

    cout << ans;
    
    return 0;
}
