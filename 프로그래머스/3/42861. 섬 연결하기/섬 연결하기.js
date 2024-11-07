

function solution(n, costs) {
    var answer = 0;
    
    let parent = Array.from({length:n}, (_, i) => i);
    let graph = Array.from({length:n}, () => new Array());
    
    
    const getParent = (x) =>{
        if(x!= parent[x]){
            return getParent(parent[x]);
        }
        return x;
    }
    
    const unite = (a,b) =>{
        let pa = getParent(a);
        let pb = getParent(b);
        
        if(pa!=pb){
            parent[pa] = pb;
            
        }
    }

    costs.sort((a,b) => a[2] - b[2]);
    //console.log(costs);
    costs.forEach((edge) => {
        if(getParent(edge[0]) != getParent(edge[1])){
            //console.log(edge[0], edge[1]);
            unite(edge[0],edge[1])
            answer += edge[2];
        }
    })
    
    return answer;
}