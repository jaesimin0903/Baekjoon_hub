#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {

	//4 , 7의 구간이 존재한다면 첫번째 사람이 7개의 경우 두번째 사람이 6 세 5 네 4 의 경우가 생성되고 위모든 값을 곱한게 답이다.
	//점화식 dp[i+2] = dp[i+1] * dp[i]

	int T;
	cin >> T;
	int dp[1001][2] = { 0, };
	//dp[0] -1 -3 4 2
	//dp[1] -1 -3 1 1
	//dp[2] -1 -3 0
	dp[0][0] = T;
	dp[0][1] = T;
	int idx = 1;
	while (1) {
	
		dp[idx][0] = max(dp[idx - 1][0] - 1, dp[idx - 1][1] - 3);
		dp[idx][1] = max(dp[idx - 1][1] - 1, dp[idx - 1][1] - 3);

		if (dp[idx][0] == 0 || dp[idx][1] == 0) {
			if (idx % 2 == 0) cout << "CY";
			else cout << "SK";
			break;
		}
		idx++;
	}
	return 0;
}