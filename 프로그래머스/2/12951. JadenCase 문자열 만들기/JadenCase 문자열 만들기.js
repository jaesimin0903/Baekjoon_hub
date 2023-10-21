function solution(s) {
    var answer = '';
    var words = s.split(' ')
    var isNumber = Array(words.length).fill(false)
    for(var i = 0;i<words.length;i++){
        if(words.length === 0) continue
        var w = words[i].split('')
        for(var j = 0;j<w.length;j++){
            //숫자확인
            if(w[j].charCodeAt(0)<65){
                isNumber[i] = true
            } 
        }
        //숫자 포함 아니라면
        if(!isNumber[i]){
            for(var j = 0;j<w.length;j++){
                if(w[j].charCodeAt(0)>=97){
                    if(j===0){
                        w[j] = String.fromCharCode(w[j].charCodeAt(0)-32)
                    }
                }
                else{
                    if(j!==0)w[j] = String.fromCharCode(w[j].charCodeAt(0)+32)
                }
            }
        }
        //숫자 포함 이라면
        else{
            for(var j = 0;j<w.length;j++){
                if(w[j].charCodeAt(0) >=65){
                    if(w[j].charCodeAt(0)<97){
                        w[j] = String.fromCharCode(w[j].charCodeAt(0)+32)
                    }
                }
            }
        }
        words[i] = w
    }
    console.log(words)
    for(var i = 0;i<words.length;i++){
        // if(words[i].length===0) continue
    answer+=words[i].join('') 
        if(i!==words.length-1) answer+=" "
    }
    return answer;
}

//ascii 로 숫자 문자 판별
//숫자면? 숫자제외 모든 소문자화
//단어면? 맨앞만 대문자 나머지 소문자화