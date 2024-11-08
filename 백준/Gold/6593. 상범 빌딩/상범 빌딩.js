const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let index = 0;
const cases = [];

while (true) {
  const [L, R, C] = input[index++].split(" ").map(Number);

  if (L === 0 && R === 0 && C === 0) break;

  const building = [];
  for (let l = 0; l < L; l++) {
    const floor = [];
    for (let r = 0; r < R; r++) {
      floor.push(input[index++].trim());
    }
    building.push(floor);
    index++; // 빈 줄 건너뛰기
  }
  cases.push([L, R, C, building]);
}

let dy = [-1, 0, 1, 0, 0, 0];
let dx = [0, -1, 0, 1, 0, 0];
let dz = [0, 0, 0, 0, 1, -1];

// cases 배열에 각 테스트 케이스가 저장되어 있음
cases.forEach((c) => {
  let [L, R, C, building] = [...c];
  let start = null;
  let canEscape = false;

  // 시작 위치(S) 찾기
  outerLoop:
  for (let l = 0; l < L; l++) {
    for (let r = 0; r < R; r++) {
      for (let c = 0; c < C; c++) {
        if (building[l][r][c] === 'S') {
          start = [l, r, c];
          break outerLoop;
        }
      }
    }
  }

  // 시작 위치가 없을 경우, Trapped로 처리
  if (!start) {
    console.log("Trapped!");
    return;
  }

  let v = Array.from({ length: L }, () => Array.from({ length: R }, () => Array.from({ length: C }, () => false)));
  const oob = (z, y, x) => z < 0 || y < 0 || x < 0 || z >= L || y >= R || x >= C;

  // BFS 시작
  let q = [];
  q.push([...start, 0]);
  v[start[0]][start[1]][start[2]] = true;

  while (q.length > 0) {
    let [z, y, x, cnt] = q.shift();

    if (building[z][y][x] === 'E') {
      console.log(`Escaped in ${cnt} minute(s).`);
      canEscape = true;
      break;
    }

    for (let d = 0; d < 6; d++) {
      let nz = z + dz[d];
      let ny = y + dy[d];
      let nx = x + dx[d];

      if (oob(nz, ny, nx)) continue;
      if (building[nz][ny][nx] === '#') continue;
      if (v[nz][ny][nx]) continue;

      v[nz][ny][nx] = true;
      q.push([nz, ny, nx, cnt + 1]);
    }
  }

  if (!canEscape) {
    console.log("Trapped!");
  }
});
