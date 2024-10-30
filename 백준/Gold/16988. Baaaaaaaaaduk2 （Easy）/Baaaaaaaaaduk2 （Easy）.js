const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

let [N, M] = input[0].split(' ').map(Number);
input.shift();
let map = [];
input.forEach(v => map.push(v.split(' ').map(Number)));

//console.log(map);

let dy = [-1,0,1,0];
let dx = [0,1,0,-1];
let answer =0;

for (let fi = 0; fi < N; fi++){
  for (let fj = 0; fj < M; fj++){
    for (let si = 0; si < N; si++){
      for (let sj = 0; sj < M; sj++){
        if ((fi === si) && (fj === sj)) continue;
        if (map[fi][fj] === 1 || map[fi][fj] === 2 || map[si][sj] === 1 || map[si][sj] === 2) continue;
        map[fi][fj] = 1;
        map[si][sj] = 1;
        let v = Array.from({ length: N }, () => Array(M).fill(false));
        let sum = 0;
        for (let row = 0; row < N; row++) {
          for (let col = 0; col < M; col++){
            if (map[row][col] === 2 && !v[row][col]) {
              v[row][col] = true;
              let q = [];
              let isNearByZero = false;
              let part = 0;
              q.push([row,col]);
                // bfs //
              while(q.length > 0){
                let [curY, curX] = q.shift();
                part++;
                for(let d = 0;d<4;d++){
                    let ny = curY + dy[d];
                    let nx = curX + dx[d];
                    if(ny < 0 || nx < 0 || ny >= N || nx >= M ) continue;
                    if(v[ny][nx])continue;
                    //console.log("주위를 둘러봐라", map[ny][nx])
                    if(map[ny][nx] === 0) isNearByZero = true;
                    else if(map[ny][nx] === 2){
                        v[ny][nx] = true;
                        q.push([ny,nx]);
                    }
                }
              }
              if(!isNearByZero){
                sum += part;
              }
          }
        }
      }

      map[fi][fj] = 0;
      map[si][sj] = 0;
      answer = Math.max(answer, sum);
    }
  }
}
}
console.log(answer);