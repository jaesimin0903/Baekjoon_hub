const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let N = Number(input[0]);
let K = Number(input[1]);

let B = [];

function findKthNumber(N, k) {
  let left = 1, right = N * N;

  while (left < right) {
    let mid = Math.floor((left + right) / 2);
    let count = 0;

    for (let i = 1; i <= N; i++) {
      count += Math.min(Math.floor(mid / i), N);
    }

    if (count < k) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}

console.log(findKthNumber(N, K));