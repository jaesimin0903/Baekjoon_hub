function solution(k, tangerine) {
    var answer = 0;
    
    var map = new Map();
    var list = [];
    tangerine.forEach(i=>{
        if(map.has(i)){
            map.set(i,map.get(i)+1);
        }else{
            map.set(i,1);
        }
    })
    var s = new Set();
    
    for(let [key,value] of map){
        list.push([key,value]);
    }
    
    list.sort((a,b)=> b[1] - a[1])
    
    console.log(list)
    
    for(let i = 0;i<list.length;i++){
        if(k <=0)break;
        
        k-= list[i][1]
        answer++;
    }
    
    //answer = s.size;
    
    return answer;
}