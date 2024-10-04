function solution(topping) {
    var answer = 0;
    
    let p = []
    let r = []
    
    let setP = new Set();
    let setR = new Set();
    
    for(let i = 0;i<topping.length;i++){
        if(setP.has(topping[i])){
            p.push(setP.size);
        }else{
            setP.add(topping[i]);
            p.push(setP.size);
        }
    }
    
    for(let i = topping.length-1;i>=0;i--){
        if(setR.has(topping[i])){
            r.push(setR.size);
        }else{
            setR.add(topping[i]);
            r.push(setR.size);
        }
    }
    r.reverse();
    //console.log(p,r);
    for(let i =0;i<p.length-1;i++){
        //console.log(p[i], r[i+1])
        if(p[i] == r[i+1]){
            answer++;
        }
    }
    return answer;
}

//1 2 2 3 3 4 4 4 
//4 4 4 4 3 3 2 1