function solution(triangle) {
    var answer = 0;
    var leng = triangle.length;
    var dp = Array.from({length: leng}, () => new Array(leng).fill(0));
    
    dp[0][0] = triangle[0][0];
    

    for(let i = 1;i<triangle.length;i++){
        for(let j = 0;j<triangle[i].length;j++){
            if(j==0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }else{
            dp[i][j] = Math.max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
                                
            }
        }
    }
        for(var row of dp){
        for(var v of row){
            //console.log(v);
        }
    }
    for(let i = 0;i<leng;i++){
        answer = Math.max(answer, dp[leng-1][i]);
    }
    return answer;
}

//7
//3 8
//8 1 0
//2 7 4 4
//4 5 2 6 5

//7
//10 15
//18 16
