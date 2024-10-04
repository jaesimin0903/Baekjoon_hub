function solution(gems) {
    const gemTypes = new Set(gems).size;  // 모든 보석의 종류 수
    const gemMap = new Map();  // 구간 내 보석 개수 카운트
    let start = 0, end = 0;  // 투 포인터 초기화
    let minStart = 0, minEnd = gems.length - 1;  // 최소 구간 저장
    let minLength = gems.length;  // 최소 구간의 길이
    
    while (end < gems.length) {
        // end 포인터를 이동시키면서 보석 추가
        gemMap.set(gems[end], (gemMap.get(gems[end]) || 0) + 1);
        end++;  // 구간을 넓힘
        
        // 현재 구간에 모든 보석이 포함되었을 경우, 구간을 줄이기 시작
        while (gemMap.size === gemTypes) {
            // 현재 구간이 최소 구간보다 작으면 갱신
            if (end - start < minLength) {
                minStart = start;
                minEnd = end - 1;
                minLength = end - start;
            }
            
            // start 포인터 이동 (구간 줄임)
            gemMap.set(gems[start], gemMap.get(gems[start]) - 1);
            
            // 보석 수가 0이 되면 해당 보석을 맵에서 제거
            if (gemMap.get(gems[start]) === 0) {
                gemMap.delete(gems[start]);
            }
            start++;  // 구간을 줄임
        }
    }
    
    // 1번 진열대가 1부터 시작하므로 인덱스에 1씩 더해서 반환
    return [minStart + 1, minEnd + 1];
}
