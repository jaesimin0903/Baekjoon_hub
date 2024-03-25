function solution(n) {
    var answer = 0;
    
    let dp = new Array(2001).fill(0);
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(let i = 3;i<=n;i++){
        dp[i] =(dp[i-1] + dp[i-2])%1234567;
        //console.log(dp[i]);
    }
    answer = dp[n];
    
    return answer;
}