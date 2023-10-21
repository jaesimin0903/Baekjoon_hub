function solution(tickets) {
    var answer = [];
    var result = []
    var visited =[]
    
    
    tickets.sort()
    

    
    var len = tickets.length;
        visited = Array(len).fill(false)
    
    const dfs = (str, count) =>{
        result.push(str);
        console.log(str)
        if(count == len){
            answer = result
            return true
        }
        
        for (var i = 0;i<len;i++){
            if(!visited[i] && tickets[i][0] ===str){
                visited[i] = true
                if(dfs(tickets[i][1],count+1)) return true
                
                visited[i] = false
            }
        }
        result.pop()
        
        return false
    }
    
    dfs("ICN",0)
    

    
    
    return answer;
}