#include <string>
#include <vector>

using namespace std;

long long answer = 0;
int N;
//1: 1 , 2: 2, 3: 3 4: 5
//5 : 11111 1112 1121 1211 2111 221 212 122

long long dp[2001];

long long solution(int n) {
    N = n;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2])%1234567;
    }
    
    answer = dp[n];
    return answer;
}