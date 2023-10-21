function solution(n, computers) {
    var answer = 0;
    
    var q = []
    var visited = Array(n).fill(false)
    for(var i =0 ;i<n;i++){
        q.push(i)
        if(visited[i] == false) answer++
        while(q.length){
            var current = q.shift()
            if(!visited[current]){
                visited[current]=1
            for(var j =0;j<n;j++){
                if(j!==current && computers[current][j] === 1)
                    q.push(j)
                }
            }
        }
            
        
    }
    
    return answer;
}

//자기네트워크는 제외하고 다음 1번 인덱스를 찾는다
//없으면 순회를 끝낸다.
//있으면 다음 네트워크로 이동한다. 다음 컴퓨터에서 나의 인덱스와 이전 인덱스를 제외하고
//다음 1인 인덱스를 찾는다.
//bfs로 하게 된다면 컴퓨터의 연결리스트를 큐에 저장