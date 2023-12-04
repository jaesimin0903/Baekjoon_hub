
function dp(n){
    let d = new Array(100001).fill(0);
    d[0] = 0;
    d[1] = 1;
    for(let i = 2;i<=n;i++){
        d[i] = (d[i-1]%1234567 + d[i-2]%1234567)%1234567;
    }
    
    return d[n];
}

function solution(n) {
    var answer = 0;
    
    answer = dp(n);
    return answer;
}
