function solution(s){
    var str = s.split('')
    var stack = []

    if(str[0] == ')') return false
    str.map((st)=>{
        if(st =='(')
            stack.push(st)
        else{
            stack.pop()
        }
    })
   
    return stack.length == 0;
}