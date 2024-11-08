const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let N = Number(input.shift());
let arr = Array.from({ length: N }, () => 1);  // 1: 닫힌 문, 0: 열린 문
let openDoor = input.shift().split(' ').map(Number).map(x => x - 1);  // 인덱스 맞추기
let leng = Number(input.shift());
let order = input.map(Number).map(x => x - 1);  // 사용할 벽장 순서 인덱스 맞추기

// dp 배열 초기화
let dp = Array.from({ length: N }, () => Array.from({ length: N }, () => Array(leng + 1).fill(Infinity)));
dp[openDoor[0]][openDoor[1]][0] = 0;

// DP 계산
order.forEach((door, idx) => {
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (dp[i][j][idx] !== Infinity) {
        // j를 target(door)으로 이동하는 경우
        dp[i][door][idx + 1] = Math.min(dp[i][door][idx + 1], dp[i][j][idx] + Math.abs(j - door));
        // i를 target(door)으로 이동하는 경우
        dp[door][j][idx + 1] = Math.min(dp[door][j][idx + 1], dp[i][j][idx] + Math.abs(i - door));
      }
    }
  }
});

// 결과 계산
let minMoves = Infinity;
for (let i = 0; i < N; i++) {
  for (let j = i + 1; j < N; j++) {
    minMoves = Math.min(minMoves, dp[i][j][leng]);
  }
}

console.log(minMoves);
