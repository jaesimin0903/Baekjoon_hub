const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "") // 정규 표현식으로 \r을 제거
  .trim()
  .split("\n")
  .map(String);

let A = input[0];
let B = input[1];

let dp = Array.from({ length: A.length + 1 }, () => Array(B.length + 1).fill(0));

for (let i = 0; i <= A.length; i++) {
  for (let j = 0; j <= B.length; j++) {
    if (i == 0 || j == 0) dp[i][j] = 0;
    else if (A[i - 1] == B[j - 1]) {
      dp[i][j] = dp[i - 1][j - 1] + 1;
    } else {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
}

console.log(dp[A.length][B.length]);

let curI = A.length;
let curJ = B.length;
let ans = "";
while (dp[curI][curJ] != 0) {
  if (A[curI - 1] == B[curJ - 1] && dp[curI - 1][curJ - 1] == dp[curI][curJ] - 1) {
    ans += B[curJ - 1];
    curI--;
    curJ--;
  } else if (dp[curI - 1][curJ] > dp[curI][curJ - 1]) {
    curI--;
  } else {
    curJ--;
  }
}

console.log(ans.split("").reverse().join(""));
