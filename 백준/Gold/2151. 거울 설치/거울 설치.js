const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let N = Number(input[0]);
input.shift();

let map = input;

let dy = [-1, 0, 1, 0];
let dx = [0, 1, 0, -1];

let start = null,
  end = null;

// 시작과 끝 문 위치 찾기
for (let i = 0; i < N; i++) {
  for (let j = 0; j < N; j++) {
    if (map[i][j] === "#") {
      if (!start) {
        start = [i, j];
      } else {
        end = [i, j];
      }
    }
  }
}

// 방문 배열 초기화 (3차원 배열로, 각 위치에서 방향별 최소 거울 개수 기록)
let visited = Array.from({ length: N }, () =>
  Array.from({ length: N }, () => Array(4).fill(Infinity))
);
let queue = [];

// 시작점에서 4방향으로 초기화
for (let dir = 0; dir < 4; dir++) {
  queue.push([start[0], start[1], dir, 0]);
  visited[start[0]][start[1]][dir] = 0;
}

while (queue.length > 0) {
  let [curY, curX, dir, mirrors] = queue.shift();

  // 종료 조건: 도착 문에 도달
  if (curY === end[0] && curX === end[1]) {
    console.log(mirrors);
    return;
  }

  // 현재 방향으로 계속 이동
  let ny = curY + dy[dir];
  let nx = curX + dx[dir];

  while (ny >= 0 && nx >= 0 && ny < N && nx < N && map[ny][nx] !== "*") {
    // 같은 방향으로 이동할 때 최소 거울 개수 갱신
    if (visited[ny][nx][dir] > mirrors) {
      visited[ny][nx][dir] = mirrors;
      queue.push([ny, nx, dir, mirrors]);
    }

    // 거울 설치 가능 위치(!)에서 방향 전환
    if (map[ny][nx] === "!") {
      // 90도 회전 가능 (0<->2, 1<->3)
      for (let turn of [(dir + 1) % 4, (dir + 3) % 4]) {
        if (visited[ny][nx][turn] > mirrors + 1) {
          visited[ny][nx][turn] = mirrors + 1;
          queue.push([ny, nx, turn, mirrors + 1]);
        }
      }
    }

    // 다음 위치로 이동
    ny += dy[dir];
    nx += dx[dir];
  }
}
