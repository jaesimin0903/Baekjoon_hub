function solution(n) {
    var answer = 0;
    var start =1
    while(start<=n){
        var sum = 0
        for(var i = start;i<=n;i++){
            sum += i
            if(sum === n){
            
          answer++
            
                break
        }
            else if(sum>n){
                break
            }
        }
        start++
    }
    return answer;
}