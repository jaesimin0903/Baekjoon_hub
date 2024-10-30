const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, M] = input[0].split(" ").map(Number);
input.shift();

let degree = Array(N + 1).fill(0);
let graph = Array.from({ length: N + 1 }, () => []);
input.forEach((v) => {
  let [f, l] = v.split(" ").map(Number);
  degree[l]++;
  graph[f].push(l);
});

class PQ {
  constructor() {
    this.heap = [];
  }

  push(val) {
    this.heap.push(val);
    this._bubbleUp();
  }

  pop() {
    if (this.heap.length === 0) {
      return;
    } else {
      this._swap(0, this.heap.length - 1);
      const min = this.heap.pop();
      this._bubbleDown();
      return min;
    }
  }

  _bubbleUp() {
    let idx = this.heap.length - 1;
    while (idx > 0) {
      let parentIdx = Math.floor((idx - 1) / 2);
      if (this.heap[idx] >= this.heap[parentIdx]) break;
      this._swap(idx, parentIdx);
      idx = parentIdx;
    }
  }

  _bubbleDown() {
    let index = 0;
    const length = this.heap.length;
    while (true) {
      let leftChildIndex = 2 * index + 1;
      let rightChildIndex = 2 * index + 2;
      let smallest = index;

      if (leftChildIndex < length && this.heap[leftChildIndex] < this.heap[smallest]) {
        smallest = leftChildIndex;
      }
      if (rightChildIndex < length && this.heap[rightChildIndex] < this.heap[smallest]) {
        smallest = rightChildIndex;
      }
      if (smallest === index) break;
      this._swap(index, smallest);
      index = smallest;
    }
  }
  // 두 요소의 위치를 교환
  _swap(i, j) {
    [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
  }
}
let total = 0;
let ans = [];
let pq = new PQ();

function chainDegree(val) {
  for (let i = 0; i < graph[val].length; i++) {
    if (--degree[graph[val][i]] === 0) {
      degree[graph[val][i]] = -1;
      pq.push(graph[val][i]);
      chainDegree(graph[val][i]);
    }
  }
}

for (let i = 1; i <= N; i++) {
  if (degree[i] === 0) {
    pq.push(i);
  }
}

while (pq.heap.length > 0) {
  let cur = pq.pop();
  ans.push(cur);

  for (const child of graph[cur]) {
    degree[child]--;
    if (degree[child] === 0) {
      pq.push(child);
    }
  }
}

let answer = "";

ans.forEach((v) => (answer += v + " "));
console.log(answer);
