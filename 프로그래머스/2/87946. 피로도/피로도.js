var answer = -1;

function dfs(num,idx, dungeons, v ,cnt){
    answer = Math.max(cnt, answer);
    
    if(num <= 0) return;
    
    for(let i = 0;i<dungeons.length;i++){
        if(v[i]) continue;
        if(i == idx) continue;
        if(dungeons[i][0] <= num && dungeons[i][1] <= num){
            v[i] = true;
            dfs(num - dungeons[i][1], i, dungeons, v, cnt+1);
            v[i] = false;
        }
        
        
    }
}

function solution(cur, dungeons) {
   
    
    let v = Array(dungeons.length).fill(false);
    for(let i = 0;i<dungeons.length;i++){
        if(dungeons[i][0] <= cur && dungeons[i][1] <= cur){
            v[i] = true;
            dfs(cur - dungeons[i][1], i, dungeons, v, 1);  
            v[i] = false;
        }
    }
    
    return answer;
}