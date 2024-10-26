#include <iostream>
#include <vector>
#include <algorithm>  // min 함수 사용을 위해 추가
#include <unordered_set>
using namespace std;

int dp[4010][4010];

int main() {
    string A, B;
    cin >> A >> B;

    int ans = 0;
    for (int i = 0; i <= A.size(); i++) {
        for (int j = 0; j <= B.size(); j++) {
            if (i == 0 || j == 0) dp[i][j] = 0;
            else if (A[i - 1] == B[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }

    //for (int i = 0; i <= A.size(); i++) {
    //    for (int j = 0; j <= B.size(); j++) {
    //        cout << dp[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    cout << ans;

    return 0;
}
