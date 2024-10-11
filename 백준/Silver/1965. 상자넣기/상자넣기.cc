#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int N;

int main() {
    
    int arr[1010];
    int dp[1010];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >>arr[i];
        dp[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j])dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;

    return 0;
}
