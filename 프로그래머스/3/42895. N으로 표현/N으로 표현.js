function solution(N, number) {
    var answer = -1;
    
    var dp = new Array(8).fill().map(()=>new Set());
    
    var sum = 0;
    for(let i = 0;i<8;i++){
        sum = 10 * sum +N;
        dp[i].add(sum);
    }
    
    for(let i = 1;i<8;i++){
        for(let j = 0; j<i;j++){
            dp[j].forEach((a) =>{
                dp[i-j-1].forEach((b)=>{
                    dp[i].add(a+b);
                    dp[i].add(a-b);
                    dp[i].add(a*b);
                    if(b!=0)
                        dp[i].add(a/b);
                })
            })
        }
    }
    
    for(let i =0;i<8;i++){
        if(dp[i].has(number)){
            answer = i+1;
            break;
        }
    }
    
    
    return answer;
}