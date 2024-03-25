function solution(elements) {
    var answer = 0;
    
    var window = 1;
    
    var leng = elements.length;
    var set = new Set();
    while(window <= leng){
        for(let i = 0;i<leng;i++){
            var sum =0;
            for(let j = i;j<i+window;j++){
                if(j>=leng){
                    sum+=elements[j-leng];
                }else{
                    sum+=elements[j];
                }
            }
            set.add(sum);
            sum =0;
        }
        window++;
    }
    answer = set.size;
    return answer;
}