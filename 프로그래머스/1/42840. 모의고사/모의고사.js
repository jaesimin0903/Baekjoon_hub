function solution(answers) {
    var answer = [];
    var a = [1,2,3,4,5]
    var b = [2,1,2,3,2,4,2,5]
    var c= [3,3,1,1,2,2,4,4,5,5]
    
    var aa=0
    var bb=0
    var cc=0
    
    for(var i = 0;i<answers.length;i++){
        if(answers[i] == a[i%5])
            aa++
        if(answers[i] == b[i%8])
            bb++
        if(answers[i] == c[i%10])
            cc++
    }
    
    var list = []
    list.push([1,aa])
    list.push([2,bb])
    list.push([3,cc])
    
    list.sort((a,b)=>b[1]-a[1])
    console.log(list)
    
    answer.push(list[0][0])
    if(list[0][1] === list[1][1]){
        answer.push(list[1][0])
        if(list[1][1]===list[2][1]){
            answer.push(list[2][0])
        }}
    return answer.sort((a,b)=>a-b);
}

//12345
//21232425
//3311224455