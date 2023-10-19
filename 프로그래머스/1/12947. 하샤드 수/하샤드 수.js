function solution(x) {
    var answer = true;
    
    var str = x.toString()
    var sum = 0
    str.split("").forEach((a)=>{
        sum+=parseInt(a)
    })
    console.log(sum)
    if(x%sum != 0) return false
    return answer;
}