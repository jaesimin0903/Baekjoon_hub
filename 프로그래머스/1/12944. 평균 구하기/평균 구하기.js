function solution(arr) {
    var answer = 0;
    var sum = 0
    arr.forEach((n)=>{
        sum+=n
    })
    answer = sum/arr.length
    return answer;
}