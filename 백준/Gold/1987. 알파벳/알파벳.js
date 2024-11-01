const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, M] = input[0].split(' ').map(Number);
input.shift();

let map = [];
input.forEach((v) => map.push(v));

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

function oob(y, x) {
  return y < 0 || x < 0 || y >= N || x >= M;
}

let answer = 0;
let v = Array.from({ length: N }, () => Array(M).fill(false));
let visited = 0;

function dfs(y, x, count) {
  answer = Math.max(answer, count);

  for (let d = 0; d < 4; d++) {
    let ny = y + dy[d];
    let nx = x + dx[d];
    if (oob(ny, nx)) continue;
    if (v[ny][nx]) continue;

    const charCode = map[ny][nx].charCodeAt(0) - 65; // 'A'를 0으로 맞추기
    if (visited & (1 << charCode)) continue; // 이미 방문한 문자면 패스

    visited |= (1 << charCode); // 문자 추가
    v[ny][nx] = true;
    dfs(ny, nx, count + 1);
    visited &= ~(1 << charCode); // 문자 제거
    v[ny][nx] = false;
  }
}

const startCharCode = map[0][0].charCodeAt(0) - 65;
visited |= (1 << startCharCode);
v[0][0] = true;
dfs(0, 0, 1);
console.log(answer);
