function solution(maps) {
    var answer = 0;
    
    const q = []
    q.push([0,0,1])
    while(q.length){

        var [y,x,g] = q.shift()
        
        if(0>x||x>=maps[0].length) continue
        if(0>y||y>=maps.length) continue
        if(maps[y][x]===0) continue

        //console.log(x,y,answer)
        if(y==maps.length-1 && x==maps[0].length-1) {
            if(g === 0)return -1
        return g
            
        }
        maps[y][x] = 0
        q.push([y+1,x,g+1])
        q.push([y,x+1,g+1])
        q.push([y,x-1,g+1])
        q.push([y-1,x,g+1])
        
        
    }
    return -1
}

// function dfs(maps,i,j,v,sum){
//     if(i>=maps[0].length || j>=maps.length||i<0||j<0) return;
    
//     if(maps[i][j] ===1)
//         v[i][j] = sum
//     else return;
    
//     console.log(sum)
//     if(i===maps[0].length-1 && j===maps.length) return;
//     if(i+1 < maps[0].length&&v[i][j] <= v[i+1][j]  )
//        dfs(maps,i+1,j,v,sum+1)
//     if(j+1 < maps.length&&v[i][j] <= v[i][j+1]  )
//         dfs(maps,i,j+1,v,sum+1)
//     if(i-1<0 &&v[i][j] <= v[i-1][j])
//         dfs(maps,i-1,j,v,sum+1)
//     if(j-1 <0&&v[i][j] <= v[i][j-1]  )
//         dfs(maps,i,j-1,v,sum+1)
// }