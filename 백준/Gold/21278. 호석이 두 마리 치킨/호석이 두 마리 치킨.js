const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, M] = input[0].split(" ").map(Number);
input.shift();

let graph = Array.from({ length: N + 1 }, () => Array(N + 1).fill(Infinity));

for (let i = 0; i < M; i++) {
  let [s, e] = input[0].split(" ").map(Number);
  input.shift();
  graph[s][e] = 1;
  graph[e][s] = 1;
}

for (let k = 1; k <= N; k++) {
  for (let i = 1; i <= N; i++) {
    for (let j = 1; j <= N; j++) {
      graph[i][j] = Math.min(graph[i][j], graph[i][k] + graph[k][j]);
    }
  }
}

let minSum = 1e9;
let min1, min2;
for (let i = 1; i <= N; i++) {
  for (let j = i + 1; j <= N; j++) {
    let part = 0;
    for (let k = 1; k <= N; k++) {
      if (k !== i && k !== j) {
        part += Math.min(graph[k][i], graph[k][j]) * 2;
      }
    }
    if (minSum > part) {
      minSum = part;
      min1 = i;
      min2 = j;
    } else if (minSum === part) {
      if (min1 > i) {
        min1 = i;
        min2 = j;
      } else {
        if (min2 > j) {
          min1 = i;
          min2 = j;
        }
      }
    }
  }
}

//console.log(graph);
console.log(min1, min2, minSum);
