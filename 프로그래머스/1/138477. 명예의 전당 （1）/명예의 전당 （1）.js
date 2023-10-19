function solution(k, score) {
    var answer = [];
    
    var list =[];
    
    for(var i = 0;i<score.length;i++){
        list.push(score[i])
        list.sort((a,b)=>b-a)
        if(list.length <= k)
            answer.push(list[list.length-1])
        else{
            list.pop()
            answer.push(list[k-1])
        }
    }
    return answer;
}