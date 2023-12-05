function solution(n, s) {
    var answer = [];
    
    let divide = Math.floor(s/n);
    let divide_arr = new Array(n).fill(divide);
    
    if(divide === 0){
        return [-1];
    }
    
    let rest = s%n;
    let mul = 1;
    for(let i = 0;i<rest;i++){
        divide_arr[i]+=1;
    }
    
    //console.log(divide_arr);
    divide_arr.sort();
    answer = divide_arr;
    return answer;
}