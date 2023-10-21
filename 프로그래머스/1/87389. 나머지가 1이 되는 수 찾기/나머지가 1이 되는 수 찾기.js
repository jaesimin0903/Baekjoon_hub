function solution(n) {
    var answer = 0;
    for(var i = n;i>0;i--){
        if(n%i==1) answer = i
    }
    return answer;
}