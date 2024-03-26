function solution(m, n, puddles) {
    var answer = 0;
    const mm = 1000000007;
    var dp = Array.from({length:n}, ()=>new Array(m).fill(0))
    
    
    puddles.forEach((p)=>{
        dp[p[1]-1][p[0]-1] = -1;
    })
    dp[0][0] = 1;
    

    
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (dp[i][j] == -1) continue; // 웅덩이는 건너뛰기

            if (i > 0 && dp[i - 1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mm; // 위에서 오는 경로 추가
            }
            if (j > 0 && dp[i][j - 1] != -1) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mm; // 왼쪽에서 오는 경로 추가
            }
        }
    }
    

    answer = dp[n-1][m-1];
    return answer;
}