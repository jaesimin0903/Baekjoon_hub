const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    sum = "";
    for(var i= 0;i<str.length;i++){
        
        if(str[i].charCodeAt(0) >= 97){
            sum+=String.fromCharCode(str[i].charCodeAt(0)-32)
        }else{
            sum+=String.fromCharCode(str[i].charCodeAt(0)+32)
        }
    }
    console.log(sum)
});