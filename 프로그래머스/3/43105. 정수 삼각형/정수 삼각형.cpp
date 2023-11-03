#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),0));
    vector<vector<int>> v;
    for(int i = 0;i<triangle.size();i++){
        v.push_back(triangle[i]);
    }
    dp[0][0] = v[0][0];
    for(int i = 0;i<triangle.size()-1;i++){
        for(int j =0;j<i+1;j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + v[i+1][j]);
            dp[i+1][j+1]  = max(dp[i+1][j+1],dp[i][j] + v[i+1][j+1]);
        }
    }
    

    answer = *max_element(dp[dp.size()-1].begin(),dp[dp.size()-1].end());
    return answer;
}