function solution(land) {
    const n = land.length; // 세로 길이
    const m = land[0].length; // 가로 길이
    let answer = 0;

    // BFS 탐색을 위한 방향 배열 (상, 하, 좌, 우)
    const directions = [
        [-1, 0], [1, 0], [0, -1], [0, 1]
    ];

    let visited = Array.from({ length: n }, () => Array(m).fill(false));
    let oilSizes = Array.from({ length: n }, () => Array(m).fill(0)); // 각 좌표에 속한 석유 덩어리의 크기 저장
    let oilIndex = 1;
    let oilSizeMap = {}; // 각 석유 덩어리의 인덱스별 크기를 저장

    // BFS로 석유 덩어리 크기 계산
    const bfs = (x, y) => {
        let queue = [[x, y]];
        let size = 1;
        visited[x][y] = true;
        oilSizes[x][y] = oilIndex;

        while (queue.length > 0) {
            const [cx, cy] = queue.shift();

            for (const [dx, dy] of directions) {
                const nx = cx + dx;
                const ny = cy + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && land[nx][ny] === 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    oilSizes[nx][ny] = oilIndex; // 같은 덩어리로 설정
                    queue.push([nx, ny]);
                    size++;
                }
            }
        }

        return size;
    };

    // 전체 맵을 탐색하여 석유 덩어리 크기 계산
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (land[i][j] === 1 && !visited[i][j]) {
                let size = bfs(i, j);
                oilSizeMap[oilIndex] = size; // 덩어리 인덱스별 크기 저장
                oilIndex++;
            }
        }
    }

    // 각 열에서 석유 덩어리의 크기를 합산
    for (let j = 0; j < m; j++) {
        let oilSet = new Set(); // 각 열에서 중복되지 않는 석유 덩어리만 계산
        for (let i = 0; i < n; i++) {
            if (land[i][j] === 1) {
                oilSet.add(oilSizes[i][j]); // 해당 열에서 만나게 되는 석유 덩어리의 인덱스 추가
            }
        }
        
        // 해당 열에서 얻을 수 있는 석유량 계산
        let totalOil = 0;
        oilSet.forEach(oilIdx => {
            totalOil += oilSizeMap[oilIdx]; // 석유 덩어리 크기를 합산
        });

        answer = Math.max(answer, totalOil); // 최대값 갱신
    }

    return answer;
}
