#include <iostream>
#include <vector>
#include <algorithm>  // min 함수 사용을 위해 추가

using namespace std;

int N;
int arr[1010][3];
int dp[1010][3];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        arr[i][0] = r;
        arr[i][1] = g;
        arr[i][2] = b;
    }

    int answer = 1e9;

    // 3번의 DP 실행: 첫 번째 집이 각각 빨강, 초록, 파랑일 때
    for (int firstColor = 0; firstColor < 3; firstColor++) {
        // dp 배열 초기화
        for (int i = 0; i < N; i++) {
            dp[i][0] = dp[i][1] = dp[i][2] = 1e9;  // 큰 값으로 초기화
        }

        // 첫 번째 집의 색을 고정
        dp[0][firstColor] = arr[0][firstColor];

        // DP 수행
        for (int i = 1; i < N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
        }

        // 마지막 집은 첫 번째 집과 다른 색을 선택해야 함
        for (int lastColor = 0; lastColor < 3; lastColor++) {
            if (lastColor != firstColor) {
                answer = min(answer, dp[N - 1][lastColor]);
            }
        }
    }

    cout << answer << endl;

    return 0;
}
