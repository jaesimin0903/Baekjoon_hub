function solution(k, d) {
    var answer = 0;
    
    for(var i = 0;i<=d;i+=k){
        var maxY = Math.sqrt(Math.pow(d,2)-Math.pow(i,2))
        answer += Math.floor(maxY/k) +1
    }
    return answer;
}

// 점 (a*k), (b*k) , 원점의 거리 d
// 원점과의 거리 4를 유지하면서 찍을 수 있는 가장 많은 0을 포함한 양의 자연수 점 집합의 수

//a*k, b*k 가 각각 d를 넘지 않는 조건 으로 이중 for
//생성되는 점의 거리가 d를 넘지 않으면 ++