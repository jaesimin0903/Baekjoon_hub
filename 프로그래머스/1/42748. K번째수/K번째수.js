function solution(array, commands) {
    var answer = [];
    
    for(var i = 0;i<commands.length;i++){
        var list = array.slice(commands[i][0]-1,commands[i][1])
        console.log(list)
        list.sort((a,b)=>a-b)
        answer.push(list[commands[i][2]-1])
    }
    
    return answer;
}