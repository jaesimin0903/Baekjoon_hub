const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, Q] = input[0].split(" ").map(Number);
input.shift(); // 첫 번째 줄 제거

let graph = Array.from({ length: N + 1 }, () => []);

// 그래프 생성
for (let i = 0; i < N - 1; i++) {
  let [p, q, r] = input[i].split(" ").map(Number);
  graph[p].push({ n: q, w: r });
  graph[q].push({ n: p, w: r });
}

// 다익스트라 알고리즘
const dijkstra = (k, root) => {
  let cost = Array(N + 1).fill(Infinity);
  let visited = Array(N + 1).fill(false);
  cost[root] = Infinity; // 시작점의 비용을 설정
  let pq = new PQ();
  pq.push({ n: root, w: 0 });
  visited[root] = true;

  while (pq.size() > 0) {
    let { n: cur, w: val } = pq.pop();

    if (!graph[cur]) continue; // 방어 코드: graph[cur]이 없는 경우

    for (let i = 0; i < graph[cur].length; i++) {
      let nextNode = graph[cur][i];
      let next = nextNode.n;
      let nextVal = nextNode.w;

      if (!visited[next] && nextVal >= k) {
        visited[next] = true;
        pq.push({ n: next, w: nextVal });
      }
    }
  }

  return visited.filter((v) => v).length - 1; // 시작 노드를 제외한 추천된 동영상의 수
};

class PQ {
  constructor() {
    this.values = [];
  }

  push(val) {
    this.values.push(val);
    this.values.sort((a, b) => a.w - b.w); // 가중치 기준으로 오름차순 정렬
  }

  pop() {
    return this.values.shift(); // 최소값을 꺼냄
  }

  size() {
    return this.values.length;
  }
}

// 질의 처리
let queries = input.slice(N - 1); // 질문 부분만 추출
for (let i = 0; i < Q; i++) {
  let [k, start] = queries[i].split(" ").map(Number);
  console.log(dijkstra(k, start));
}
