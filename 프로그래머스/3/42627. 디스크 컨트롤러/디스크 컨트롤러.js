class PriorityQueue {
    constructor() {
        this.heap = new Array(64);
        this.size = 0;
    }

    insert(value) {
        if (this.size + 1 === this.heap.length) {
            this.heap.length *= 2;
        }
        this.size += 1;
        this.heap[this.size] = value;
        this.percolateUp();
    }

    percolateUp() {
        let pos = this.size;
        const item = this.heap[pos];

        while (pos > 1 && this.heap[Math.floor(pos / 2)][1] > item[1]) {
            this.heap[pos] = this.heap[Math.floor(pos / 2)];
            pos = Math.floor(pos / 2);
        }
        this.heap[pos] = item;
    }

    shift() {
        const min = this.heap[1];
        if (this.size === 0) return undefined;
        this.heap[1] = this.heap[this.size];
        this.size -= 1;
        this.percolateDown(1);
        return min;
    }

    percolateDown(pos) {
        const item = this.heap[pos];

        while (pos * 2 <= this.size) {
            let child = pos * 2;
            if (child + 1 <= this.size && this.heap[child + 1][1] < this.heap[child][1]) {
                child += 1;
            }

            if (this.heap[child][1] >= item[1]) break;

            this.heap[pos] = this.heap[child];
            pos = child;
        }

        this.heap[pos] = item;
    }
}

function solution(jobs) {
    jobs.sort((a, b) => a[0] - b[0]); // 요청 시점 기준으로 정렬
    const pq = new PriorityQueue();

    let currentTime = 0;
    let idx = 0;
    let totalWaitTime = 0;
    let jobCount = jobs.length;

    while (idx < jobs.length || pq.size > 0) {
        // 대기 중인 작업들을 우선순위 큐에 삽입
        while (idx < jobs.length && jobs[idx][0] <= currentTime) {
            pq.insert(jobs[idx]);
            idx += 1;
        }

        if (pq.size > 0) {
            // 큐에서 가장 짧은 작업을 처리
            const [requestTime, duration] = pq.shift();
            currentTime += duration;
            totalWaitTime += currentTime - requestTime;
        } else {
            // 대기할 작업이 없는 경우, 다음 작업의 요청 시간으로 점프
            currentTime = jobs[idx][0];
        }
    }

    // 평균 대기 시간 계산
    return Math.floor(totalWaitTime / jobCount);
}
