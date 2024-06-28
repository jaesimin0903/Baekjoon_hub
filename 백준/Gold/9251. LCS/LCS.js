let input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const A = input[0];
const B = input[1];

let dp = Array.from({length : A.length + 1}, ()=>Array(B.length + 1).fill(0));

for(let i = 1;i<= A.length;i++){
    for(let j = 1;j<=B.length;j++){
        if(A[i-1] === B[j-1]){
            dp[i][j] = dp[i-1][j-1] + 1;
        }else{
            dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
        }
    }
}

console.log(dp[A.length][B.length]);