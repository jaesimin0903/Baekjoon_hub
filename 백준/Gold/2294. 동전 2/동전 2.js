let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

let arr = input[0].split(' ');

let N = parseInt(arr[0])
let K = parseInt(arr[1]);

let dp = Array.from({length : K + 1}, () => -1);

let coin = input.slice(1).map(Number);



dp[K] = 0;

coin.forEach((v)=>{
    dp[K-v] = 1;
})

for(let i = K;i>=0;i--){
    if(dp[i] === -1) continue;  
    for(let j = 0;j<coin.length;j++){
        if(i - coin[j] >= 0){
            if(dp[i-coin[j]] === -1) dp[i-coin[j]] = dp[i] +1;
            else dp[i - coin[j]] = Math.min(dp[i-coin[j]], dp[i] + 1);
        }
    }
}

console.log(dp[0])



