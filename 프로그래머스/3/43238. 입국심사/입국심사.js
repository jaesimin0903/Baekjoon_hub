function solution(n, times) {
    var answer = 0;
    
    let left = 0;
    let right = 1e15;
    
    while(left<=right){
        let mid = Math.floor( (left + right)/2);
        
        let howMany = 0;
        
        times.forEach((t) =>{
            howMany += Math.floor(mid / t);
        });
        
        if(howMany >= n){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return answer;
}