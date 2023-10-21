function solution(begin, target, words) {
    var answer = 0;
    
    var visited = Array(words.length).fill(false)
    var q = []
    q.push([-1,begin,answer])
    while(q.length){
        if(!words.includes(target))return 0
        console.log(q)
        var [index,current,ans] = q.shift()
        visited[index]= true

        if(current === target)
            return ans
        var b_split = current.split('')
        for(var i = 0;i<words.length;i++){
            var words_split = words[i].split('')
            var count = 0
            
            for(var j = 0;j<b_split.length;j++){
                if(b_split[j] ===words_split[j] && !visited[i]){
                    count++
                    //console.log(b_split, words_split)
                }
            }//console.log(count)
            if(count+1 === b_split.length){
                q.push([i,words[i],ans+1])
            }
        }
    }
    
    return 0;
}

//bfs
//hit 에서 한글자씩만 다른 단어들을 순회해서 찾고 큐에 삽입 앤써++
//큐에 삽입된 순서대로 같은 방법 반복
//반복할때마다 타겟이랑 일치하는지 확인