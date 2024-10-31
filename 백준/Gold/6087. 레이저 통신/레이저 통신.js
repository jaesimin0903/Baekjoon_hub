const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [M, N] = input[0].split(' ').map(Number);
input.shift();
let map = [];
input.forEach((v) => map.push(v));

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];
let answer = Infinity;

// 방문 체크 배열
let v = Array.from({ length: N }, () =>
  Array.from({ length: M }, () => Array(4).fill(Infinity))
);

let start, end;

// 시작과 끝 좌표를 찾기
for (let i = 0; i < N; i++) {
  for (let j = 0; j < M; j++) {
    if (map[i][j] === "C") {
      if (!start) start = [i, j];
      else end = [i, j];
    }
  }
}

// 우선순위 큐 구현
class PriorityQueue {
  constructor() {
    this.heap = [];
  }

  // 요소 추가
  push(value) {
    this.heap.push(value);
    this.bubbleUp();
  }

  // 요소 제거 (가장 우선순위가 높은 값)
  pop() {
    if (this.size() === 1) return this.heap.pop();
    const min = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.bubbleDown();
    return min;
  }

  // 우선순위 큐의 크기
  size() {
    return this.heap.length;
  }

  // 새 요소가 들어왔을 때 정렬(위로 올림)
  bubbleUp() {
    let index = this.heap.length - 1;
    const element = this.heap[index];
    while (index > 0) {
      let parentIndex = Math.floor((index - 1) / 2);
      let parent = this.heap[parentIndex];
      if (element[3] >= parent[3]) break;
      this.heap[index] = parent;
      index = parentIndex;
    }
    this.heap[index] = element;
  }

  // 요소 제거 후 정렬(아래로 내림)
  bubbleDown() {
    let index = 0;
    const length = this.heap.length;
    const element = this.heap[0];

    while (true) {
      let leftChildIndex = 2 * index + 1;
      let rightChildIndex = 2 * index + 2;
      let leftChild, rightChild;
      let swapIndex = null;

      if (leftChildIndex < length) {
        leftChild = this.heap[leftChildIndex];
        if (leftChild[3] < element[3]) {
          swapIndex = leftChildIndex;
        }
      }

      if (rightChildIndex < length) {
        rightChild = this.heap[rightChildIndex];
        if (
          (swapIndex === null && rightChild[3] < element[3]) ||
          (swapIndex !== null && rightChild[3] < leftChild[3])
        ) {
          swapIndex = rightChildIndex;
        }
      }

      if (swapIndex === null) break;

      this.heap[index] = this.heap[swapIndex];
      index = swapIndex;
    }
    this.heap[index] = element;
  }
}

// BFS 초기화
let q = new PriorityQueue();
for (let nd = 0; nd < 4; nd++) {
  q.push([start[0], start[1], nd, 0]);
  v[start[0]][start[1]][nd] = 0; // 초기 꺾임 수 설정
}

// BFS 실행
while (q.size() > 0) {
  let [curY, curX, bd, count] = q.pop();

  // 목적지인 또 다른 'C'에 도달했을 때 최소 꺾임 수 갱신
  if (curY === end[0] && curX === end[1]) {
    answer = Math.min(answer, count);
    break;
  }

  // 4 방향 탐색
  for (let d = 0; d < 4; d++) {
    let ny = curY + dy[d];
    let nx = curX + dx[d];

    if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
    if (map[ny][nx] === "*") continue;

    let newCount = count + (bd !== d ? 1 : 0);

    // 더 적은 꺾임 수로 방문할 수 있는 경우에만 갱신
    if (newCount < v[ny][nx][d]) {
      v[ny][nx][d] = newCount;
      q.push([ny, nx, d, newCount]);
    }
  }
}

console.log(answer);
