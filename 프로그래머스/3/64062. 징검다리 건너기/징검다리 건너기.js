function solution(stones, k) {
    var answer = 0;
    
    let left = 1;
    let right = 200000000;  // 최대로 건널 수 있는 사람 수는 돌의 최대값보다 클 수 없음
    
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        let cnt = 0;
        
        for (let i = 0; i < stones.length; i++) {
            if (stones[i] - mid <= 0) {
                cnt++;
            } else {
                cnt = 0;  // 연속된 건널 수 없는 돌을 초기화
            }
            if (cnt >= k) break;  // 연속으로 k개의 돌을 건널 수 없으면 중단
        }
        
        if (cnt >= k) {
            right = mid - 1;  // mid명이 건널 수 없다면 더 적은 인원으로 시도
        } else {
            left = mid + 1;  // mid명이 건널 수 있으면 더 많은 인원이 가능한지 확인
        }
    }
    
    return left;  // left는 최종적으로 건널 수 있는 최대 인원 수
}
