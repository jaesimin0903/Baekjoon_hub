let input = require('fs').readFileSync('/dev/stdin').toString().trim();

let N = parseInt(input);

let dp = Array.from({ length: N + 1 }, () => 100000);

for(let i = 1;i<=N;i++){
    dp[i] = i;
}
dp[0] = 0;
dp[1] = 1;
for(let i = 1;i<= N;i++){
    for(let j = 1;j*j<=i;j++){
        dp[i] = Math.min(dp[i],dp[i-j*j] + 1);
    }
}



console.log(dp[N]);