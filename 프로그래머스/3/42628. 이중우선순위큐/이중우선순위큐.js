function solution(operations) {
    var answer = [];
    
    let q = [];
    for(let i = 0;i<operations.length;i++){
        let op = operations[i].split(' ');
        
        if(op[0] === 'I'){
            q.push(parseInt(op[1]));
        }else{
            if(op[1] == '1'){
                q.pop();
            }else{
                q = q.slice(1);
            }
        }
        q.sort((a,b) => a-b);
        console.log(q);
    }
    
    if(q.length === 0){
        return [0,0];
    }else{
        return [q[q.length-1], q[0]];
    }
    
    return answer;
}