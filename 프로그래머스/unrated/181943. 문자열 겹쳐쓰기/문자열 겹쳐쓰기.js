function solution(my_string, overwrite_string, s) {
    var answer = '';
    for(var i= 0;i<s;i++){
        answer+=my_string[i]
    }
    for(var i = s;i<s+overwrite_string.length;i++){
        answer+=overwrite_string[i-s]
        
    }
    for(var i = s+overwrite_string.length;i<my_string.length;i++){
        answer+=my_string[i]
    }
    
    return answer;
}

