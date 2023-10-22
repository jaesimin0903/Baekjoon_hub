function solution(s) {
    var answer = [];
    var turn = 0;
    var del = 0;
    var str = s
    var count =0

    while(str!=='1'){
        count+=1
        var split = str.split('')
        var list =""
    for(var i = 0;i<split.length;i++){
        if(split[i] === '1') list+='1'
        else del++;
    }
        turn++
        var leng = list.length
        str= list.length.toString(2)
                console.log(list.length,str)
    }
    return [turn,del];
}