const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [K, N] = input.shift().split(' ').map(Number);
let LAN = input.map(Number);
let left = 1;
let right = Math.max(...LAN);  // right를 LAN 배열의 최대값으로 설정

while (left <= right) {
  let mid = Math.floor((left + right) / 2);
  let part = 0;

  LAN.forEach((v) => {
    part += Math.floor(v / mid);
  });

  if (part < N) {
    right = mid - 1;
  } else {
    left = mid + 1;
  }
}

console.log(right);
