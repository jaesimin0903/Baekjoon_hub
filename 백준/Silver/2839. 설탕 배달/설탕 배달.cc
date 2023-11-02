#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	//4 , 7의 구간이 존재한다면 첫번째 사람이 7개의 경우 두번째 사람이 6 세 5 네 4 의 경우가 생성되고 위모든 값을 곱한게 답이다.
	//점화식 dp[i+2] = dp[i+1] * dp[i]

	int T;
	cin >> T;
	//18
	int dp[5001];
	fill(dp, dp + 5000, -1);
	//dp[0] 13 16 
	//dp[1] 8 11
	//dp[2] -1 -3 0
	
	for (int i = 0; i <= 5001/3; i++) {
		for (int j = 0; j <= 5001/5; j++) {
			if (3 * i + 5 * j > 5000) break;
			if (dp[3 * i + 5 * j] > -1)dp[3 * i + 5 * j] = min(dp[3 * i + 5 * j], i + j);
			else dp[3 * i + 5 * j] = i + j;


		}
	}
	for (int i = 0; i < 5001; i++) {
		//cout<<i <<" : " << dp[i]<< endl;
	}
	cout << dp[T];
	return 0;
}