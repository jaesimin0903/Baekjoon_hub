const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

const bfs = (m, n, map) => {
  let answer = 0;

  let q = [];
  let dy = [-1, 1, 0, 0];
  let dx = [0, 0, -1, 1];
  let visited = Array.from({ length: map.length }, () => Array(map[0].length).fill(false));

  let row = m;
  let col = n;

  for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
      if (map[i][0][j] === "A") {
        q.push([i, j, 0]);
        visited[i][j] = true;
        while (q.length > 0) {
          let [cury, curx, day] = q.shift();
          //console.log([cury, curx, day]);
          if (map[cury][0][curx] === "B") {
            return day;
          }
          for (let d = 0; d < 4; d++) {
            let ny = cury + dy[d];
            let nx = curx + dx[d];
            if (ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
            if (map[ny][0][nx] === ".") continue;
            if (visited[ny][nx]) continue;
            if (map[ny][0][nx] !== "#" && map[ny][0][nx] !== "B") {
              for (let s = 0; s < signal.length; s++) {
                //신호등에 다다르면
                if (signal[s].idx === map[ny][0][nx]) {
                  let rest = day % (Number(signal[s].lr) + Number(signal[s].ud));
                  rest += 1;
                  // 초기 방향을 생각해서 나머지 시간에 따른 방향 확인
                  if (signal[s].dis === "-") {
                    // 초기 방향이 동서
                    // 남은 시간이 동서 시간보다 크면 남북이 켜진것이고, 트럭의 방향이 남북방향이면 움직임
                    if (rest > signal[s].lr && (d === 0 || d === 1)) {
                      //console.log("can pass ", signal[s], day, rest, "dir ", d, "cur", cury, curx);
                      q.push([ny, nx, day + 1]);
                      visited[ny][nx] = true;
                    } else if (rest <= signal[s].lr && (d === 2 || d === 3)) {
                      //console.log("can pass ", signal[s], day, rest, "dir ", d, "cur", cury, curx);
                      q.push([ny, nx, day + 1]);
                      visited[ny][nx] = true;
                    } else {
                      //가지못한다면 대기
                      q.push([cury, curx, day + 1]);
                    }
                  } else if (signal[s].dis === "|") {
                    if (rest > signal[s].ud && (d === 2 || d === 3)) {
                      q.push([ny, nx, day + 1]);
                      visited[ny][nx] = true;
                    } else if (rest <= signal[s].ud && (d === 0 || d === 1)) {
                      q.push([ny, nx, day + 1]);
                      visited[ny][nx] = true;
                    } else {
                      q.push([cury, curx, day + 1]);
                    }
                  }
                  break;
                }
              }
            } else if (map[ny][0][nx] === "#" || map[ny][0][nx] === "B") {
              q.push([ny, nx, day + 1]);
              visited[ny][nx] = true;
            }
          }
        }
      }
    }
  }

  return -1;
};
let signal = [];
let ans = 0;
let m, n;
let map = [];
input.forEach((arr) => {
  let tmp = arr.split(" ");
  if (tmp.length == 2) {
    if (tmp[0] === "0" && tmp[1] === "0") {
    } else {
      m = Number(tmp[0]);
      n = Number(tmp[1]);
    }
  } else if (tmp.length == 4) {
    signal.push({ idx: tmp[0], dis: tmp[1], lr: tmp[2], ud: tmp[3] });
  } else if (tmp[0] === "") {
    // 최단거리계산
    //console.log(map);
    //console.log(signal);
    let rs = bfs(m, n, map);
    if (rs === -1) console.log("impossible");
    else console.log(rs);

    map = [];
    signal = [];
  } else if (tmp.length == 1) {
    map.push(tmp);
  }
});
