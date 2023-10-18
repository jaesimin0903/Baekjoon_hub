function solution(cards) {
    var answer = 0;
    var ans = []
    
    var list = []
    var temp
    var a=0
    for(var i = 0;i<cards.length;i++){
        list.push(0)
    }
    
    for(var i = 0;i<cards.length;i++){
        console.log("i "+i)
        if(list[i]==0){
            
        temp = cards[i]-1
        while(list[temp]==0){
            console.log(temp+1)
            if(list[temp] == 0)
                list[temp]++
            temp = cards[temp]-1
            a++
        }
        }
ans.push(a)
        a=0
        
    }
    if(ans.length < 2) return 0
    console.log(ans)
    ans.sort((a,b)=>b-a)
    
    answer = ans[0] * ans[1]
    
    return answer;
}

//한번 연 상자를 다시 열어도 같음 flag 1
