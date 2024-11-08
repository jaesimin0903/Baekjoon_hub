const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, S] = input[0].split(' ').map(Number);
let arr = input[1].split(' ').map(Number);

// 모든 가능한 부분합을 저장하는 함수 (중복 합을 카운트)
function getSubSums(array) {
  const sums = new Map();
  const len = array.length;

  // 가능한 모든 조합의 부분합을 생성
  for (let i = 0; i < (1 << len); i++) {
    let sum = 0;
    for (let j = 0; j < len; j++) {
      if (i & (1 << j)) {
        sum += array[j];
      }
    }
    sums.set(sum, (sums.get(sum) || 0) + 1);
  }

  return sums;
}

// 배열을 절반으로 나누기
const leftArr = arr.slice(0, Math.floor(N / 2));
const rightArr = arr.slice(Math.floor(N / 2));

// 두 부분의 부분합 계산 (빈도를 고려해 저장)
const leftSums = getSubSums(leftArr);
const rightSums = getSubSums(rightArr);

let answer = 0;

// 합이 S가 되는 경우의 수 찾기
for (let [sumLeft, countLeft] of leftSums) {
  const target = S - sumLeft;
  if (rightSums.has(target)) {
    answer += countLeft * rightSums.get(target);
  }
}

// S가 0인 경우, 공집합을 포함한 경우를 제외
if (S === 0) answer -= 1;

console.log(answer);
