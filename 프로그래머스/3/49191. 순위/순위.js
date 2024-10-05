function solution(n, results) {
    var answer = 0;
    
    let wins = Array.from({ length: n + 1 }, () => []);
    let losses = Array.from({ length: n + 1 }, () => []);

    // 승리한 기록과 패배한 기록을 각각 저장
    results.forEach((arr) => {
        wins[arr[0]].push(arr[1]); // arr[0]은 arr[1]을 이김
        losses[arr[1]].push(arr[0]); // arr[1]은 arr[0]에게 짐
    });
    
    for (let i = 1; i <= n; i++) {
        let visited = Array(n + 1).fill(false);

        // BFS로 승리한 사람들 추적
        let winQueue = [i];
        visited[i] = true;
        let winCount = 0;
        while (winQueue.length > 0) {
            let cur = winQueue.shift();
            wins[cur].forEach((next) => {
                if (!visited[next]) {
                    visited[next] = true;
                    winQueue.push(next);
                    winCount++;
                }
            });
        }

        visited.fill(false);
        
        // BFS로 패배한 사람들 추적
        let loseQueue = [i];
        visited[i] = true;
        let loseCount = 0;
        while (loseQueue.length > 0) {
            let cur = loseQueue.shift();
            losses[cur].forEach((next) => {
                if (!visited[next]) {
                    visited[next] = true;
                    loseQueue.push(next);
                    loseCount++;
                }
            });
        }

        // 이긴 사람과 진 사람의 합이 n - 1이면 순서가 확정된 것
        if (winCount + loseCount === n - 1) {
            answer++;
        }
    }
    
    return answer;
}
