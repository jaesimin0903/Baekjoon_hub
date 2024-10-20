const input = require('fs').readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt").toString().trim().split("\n").map(String);

let A = input[0];
let B = input[1];
let lenA = A.length;
let lenB = B.length;

A = " " + A; // 문자열 앞에 빈 칸을 추가하여 인덱스 1부터 시작하도록
B = " " + B;

let dp = Array.from({length : lenA+1}, () => Array(lenB+1).fill(0));

// dp 배열을 이용하여 최장 공통 부분 수열 계산
for (let i = 1; i <= lenA; i++) {
    for (let j = 1; j <= lenB; j++) {
        if (A[i] === B[j]) {
            dp[i][j] = dp[i-1][j-1] + 1;
        } else {
            dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
        }
    }
}

console.log(dp[lenA][lenB]);  // 최종 답 출력
