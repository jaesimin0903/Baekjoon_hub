//n , n< N
//parseInt (n, 2) 1 count == (N, 2)
//minimum N

function solution(n) {
    var answer = 0;
    
    let n_str = n.toString(2);
    n_str = n_str.split('');
    let n_count = 0;
    for(let i = 0;i<n_str.length;i++){
        if(n_str[i] === '1'){
            n_count++;
        }
    }
    let N = n+1;
    while(1){
        let N_str = N.toString(2);
        N_str = N_str.split('');
        let N_count = 0;
        for(let i = 0;i<N_str.length;i++){
            if(N_str[i] === '1'){
                N_count++;
            }
        }
        
        if(n_count === N_count){
            answer = N;
            break;
        }
        else{
            N++;
        }
    }
    return answer;
}