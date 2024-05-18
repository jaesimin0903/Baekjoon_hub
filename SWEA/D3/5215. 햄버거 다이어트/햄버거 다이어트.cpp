#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    int test_case;
    int T;
    
    //freopen("input.txt", "r", stdin);
    cin >> T;
    
    for (test_case = 1; test_case <= T; ++test_case) {
        int N, M;
        cin >> N >> M;
        
        vector<int> v(N);
        vector<int> c(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
            cin >> c[i];
        }
        
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
        
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (c[i - 1] <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i - 1]] + v[i - 1]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        int answer = dp[N][M];
        cout << "#" << test_case << " " << answer << "\n";
    }
    
    return 0; // 정상 종료 시 반드시 0을 리턴해야 합니다.
}
