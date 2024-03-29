#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int dp[100001];
    
    dp[0] = sticker[0];
    dp[1] = sticker[1];
    dp[2] = sticker[0] + sticker[2];
    for(int i =1 ;i<sticker.size()-1;i++){
        if(i==1) dp[i] = max(dp[i], dp[i-1]);
        else dp[i] = max(dp[i-1], dp[i-2]+sticker[i]);
    }
    answer = dp[sticker.size()-2];
    
    for(int i = 0;i<sticker.size();i++){
        dp[i] = 0;
    }
    dp[1] = sticker[1];
    dp[2] = sticker[2];
    
    for(int i =2 ;i<sticker.size();i++){
        if(i==2) dp[i] = max(dp[i], dp[i-1]);
        else dp[i] = max(dp[i-1], dp[i-2]+sticker[i]);
    }
    
    answer = max(answer, dp[sticker.size()-1]);

    if(sticker.size() == 1){
        return sticker[0];
    }
    
    return answer;
}