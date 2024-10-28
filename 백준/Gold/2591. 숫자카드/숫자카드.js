const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n");

let totalStr = input[0];
let length = totalStr.length;

if (totalStr[0] === '0') {
  console.log(0);
  return;
}

let dp = Array(length).fill(0);
dp[0] = 1;

if (length > 1) {
  let firstTwoDigits = Number(totalStr.substr(0, 2));
  if (firstTwoDigits >= 10 && firstTwoDigits <= 34) dp[1] = dp[1] + 1;
  if (totalStr[1] !== '0') dp[1] = dp[1] + dp[0];
}

for (let i = 2; i < length; i++) {
  let twoDigit = Number(totalStr.substr(i - 1, 2));
  
  if (twoDigit >= 10 && twoDigit <= 34) dp[i] += dp[i - 2];
  if (totalStr[i] !== '0') dp[i] += dp[i - 1];
}

console.log(dp[length - 1]);
