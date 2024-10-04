function solution(msg) {
    var answer = [];
    
    let map = new Map();
    
    for(let i = 0;i<26;i++){
        map.set(String.fromCharCode(65+i),i+1);
    }
    
    let index = 27; 
    
    let left = 0;
    let right = 0;
    let part = "";
    while(right!=msg.length){
        if(map.has(part+msg[right])){
            part+=msg[right++];
            //console.log("-",part);
        }else{
            map.set(part+msg[right], index++);
            left = right;
            answer.push(map.get(part));
            //console.log(part+msg[right]);
            part = "";
        }
    }
    
    if(part!=""){
        answer.push(map.get(part));
    }
    
    return answer;
}