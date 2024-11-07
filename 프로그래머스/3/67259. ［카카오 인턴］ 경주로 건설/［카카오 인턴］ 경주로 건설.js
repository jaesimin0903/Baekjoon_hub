function solution(board) {
    const leng = board.length;
    const INF = 1e9;
    const dy = [0, 1, 0, -1];
    const dx = [1, 0, -1, 0];
    const cost = Array.from({ length: leng }, () => Array.from({ length: leng }, () => Array(4).fill(INF)));

    // 시작점 초기화
    const queue = [];
    for (let d = 0; d < 4; d++) {
        queue.push([0, 0, d, 0]); // [y, x, direction, sum]
        cost[0][0][d] = 0;
    }

    while (queue.length > 0) {
        const [y, x, dir, sum] = queue.shift();

        for (let d = 0; d < 4; d++) {
            const ny = y + dy[d];
            const nx = x + dx[d];

            if (ny < 0 || nx < 0 || ny >= leng || nx >= leng || board[ny][nx] === 1) continue;

            const newCost = sum + (dir === d ? 100 : 600);

            if (newCost < cost[ny][nx][d]) {
                cost[ny][nx][d] = newCost;
                queue.push([ny, nx, d, newCost]);
            }
        }
    }

    // 도착점의 네 방향에서 최소 비용 선택
    return Math.min(...cost[leng - 1][leng - 1]);
}
