let input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');

let F,S,G,U,D;

F = parseInt(input[0])
S = parseInt(input[1])
G = parseInt(input[2])
U = parseInt(input[3])
D = parseInt(input[4])

const bfs = () => {
    let visited = new Array(F + 1).fill(false);
    let q = [];
    q.push([S,0]);
    visited[S] = true;

    while(q.length > 0){
        let [cur,cnt] = q.shift();

        if(cur == G){
            return cnt;
        }

        if(cur + U <= F && !visited[cur+U]){
            visited[cur+U] = true;
            q.push([cur+U, cnt+1]);
        }

        if(cur - D >= 1 && !visited[cur-D]){
            visited[cur-D] =true;
            q.push([cur-D, cnt+1]);
        }
    }

    return "use the stairs"
}

console.log(bfs())