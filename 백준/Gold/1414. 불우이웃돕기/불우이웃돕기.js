const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let N = Number(input.shift());

let alphabetMap = new Map();

for (let i = 0; i < 26; i++) {
  alphabetMap.set(String.fromCharCode('a'.charCodeAt(0) + i), i + 1);
}

for (let i = 0; i < 26; i++) {
  alphabetMap.set(String.fromCharCode('A'.charCodeAt(0) + i), i + 27);
}

let parent = Array.from({ length: N }, (_, i) => i);

const getParent = (x) => {
  if (x != parent[x]) {
    return getParent(parent[x]);
  }
  return x;
}

const unite = (a, b) => {
  pa = getParent(a);
  pb = getParent(b);

  if (pa !== pb) {
    parent[pa] = pb;
  }
}

const same = (a, b) => {
  pa = getParent(a);
  pb = getParent(b);

  return pa === pb;
}

let edge = [];

let total = 0;

for (let i = 0; i < input.length; i++) {
  for (let j = 0; j < input[i].length; j++) {
    if (alphabetMap.has(input[i][j])) total += alphabetMap.get(input[i][j]);
    if (input[i][j] !== '0' && i !== j) {
      edge.push([i, j, alphabetMap.get(input[i][j])]);
    }
  }
}

edge.sort((a, b) => a[2] - b[2]);
//console.log(edge);
let answer = 0;

edge.forEach((e) => {
  if (!same(e[0], e[1])) {
    unite(e[0], e[1]);
    answer += e[2];
  }
})

const isConnected = () => {
  let t = getParent(0);
  for (let i = 1; i < N; i++) {
    if (t !== getParent(i)) return false;
  }
  return true;
}

if (!isConnected()) {
  console.log(-1);
}
else console.log(total - answer);