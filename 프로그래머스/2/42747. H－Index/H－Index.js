function solution(citations) {
    var answer = 0;
    citations=citations.sort((a,b)=>b-a)
    for(var i = 10000;i>=0;i--){
        var count = 0
        for(var j=0;j<citations.length;j++){
            if(i < citations[j]) count++
        }
        if(count===i){
            answer = i
            break
        }
    }
    
    return answer;
}