var a = []

function solution(maps) {
    var answer = [];
    var ans = 0
    var v = Array.from(Array(maps.length), ()=>Array(maps[0].split('').length).fill(0))
    console.log(v, maps)
    for(var i = 0;i<maps.length;i++){
        for(var j=0;j<maps[0].split('').length;j++){
    //console.log(i,j)
            a.push(0)
            dfs(maps,v,i,j,ans)

                      
        }
    }
    for(var i = 0;i<a.length;i++){
        if(a[i] !== 0)
            answer.push(a[i])
    }
    answer.sort((a,b)=>a-b)
    console.log(answer)
    if(answer.length === 0) return [-1]
    return answer;
}

function dfs(maps,v, i, j,ans){
    
    if(maps[i][j] ==='X') return;
    //if(i+1>=maps.length||j+1>=maps[0].split('').length||i-1<0||j-1<0) return;
    
    if(maps[i][j] !=='X' && v[i][j]!==1){
        ans+=parseInt(maps[i][j])
        v[i][j] = 1
        if(i+1<maps.length||j+1<maps[0].split('').length||i-1>=0||j-1>=0){
                    console.log(i,j)
            var val = a.pop()
            val +=parseInt(maps[i][j])
            a.push(val)
            if(i+1<maps.length && v[i+1][j] !== 1)
                dfs(maps,v,i+1,j,ans)
            if(j+1<maps[0].split('').length&& v[i][j+1] !== 1)
                dfs(maps,v, i,j+1,ans)  
            if(i-1>=0&& v[i-1][j] !== 1)
                dfs(maps,v,i-1,j,ans)
            if(j-1>=0&& v[i][j-1] !== 1)
                dfs(maps,v,i,j-1,ans)
        }

        
        
    }
    
    
}