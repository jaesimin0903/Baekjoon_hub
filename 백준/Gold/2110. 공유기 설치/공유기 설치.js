const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, M] = input[0].split(' ').map(Number);
input.shift();
let arr = [];
input.forEach((v) => arr.push(Number(v)));
arr.sort((a, b) => a - b);
//console.log(arr);

// let arr = Array.from({ length: Math.max(...tmp) + 1 }, () => 0);
// tmp.forEach((v) => { arr[v] = 1 });

let left = 0;
let right = 1e9;

while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  let count = 1; // 첫 번째 공유기를 설치하는 것으로 시작
  let prev = arr[0]; // 첫 공유기 설치 위치

  for (let i = 1; i < N; i++) {
    if (arr[i] - prev >= mid) {
      count++;
      prev = arr[i];
    }
  }

  if (count >= M) {
    left = mid + 1;
  } else {
    right = mid - 1;
  }
}

console.log(right);