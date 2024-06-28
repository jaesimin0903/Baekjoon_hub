function solution(nums) {
    var answer = 0;
    
    let m = new Map();
    
    nums.forEach((v) => {
        m.set(v,m.get(v) +1);
    })
    
    if(m.size < nums.length / 2) answer = m.size
    else answer = nums.length/2
    
    return answer;
}