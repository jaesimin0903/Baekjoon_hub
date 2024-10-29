const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, M] = input[0].split(" ").map(Number);
let arr = input[1].split(" ").map(Number);

// 정렬 불필요 (이분 탐색의 최댓값을 찾는 문제이므로 정렬 생략 가능)
let left = Math.max(...arr);
let right = arr.reduce((a, b) => a + b, 0);
let answer = right;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  let partSum = 0;
  let count = 1; // 최소 한 개의 부분 배열을 갖기 위해 1로 시작

  for (let i = 0; i < N; i++) {
    if (partSum + arr[i] > mid) {
      count++;
      partSum = 0;
    }
    partSum += arr[i];
  }

  if (count <= M) {
    answer = mid;
    right = mid - 1;
  } else {
    left = mid + 1;
  }
}

console.log(answer);
