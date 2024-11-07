function solution(routes) {
    var answer = 0;
    
    // 차량의 진출 지점을 기준으로 정렬
    routes.sort((a, b) => a[1] - b[1]);
    
    let cameraPosition = -30001; // 초기 카메라 위치를 충분히 작은 값으로 설정
    
    routes.forEach((car) => {
        // 현재 카메라 위치보다 더 뒤에 진입하는 차량이 있을 경우 카메라 설치
        if (cameraPosition < car[0]) {
            answer++;
            cameraPosition = car[1];
        }
    });
    
    return answer;
}
