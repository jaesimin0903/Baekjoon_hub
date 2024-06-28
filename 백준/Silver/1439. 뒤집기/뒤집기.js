let input = require('fs').readFileSync('/dev/stdin').toString().trim();

let one = 0;
let zero = 0;

let cur = input[0];
if(cur === '1') one = 1;
else zero = 1;
for(let i = 1;i<input.length;i++){
    if(cur !== input[i]){
        if(input[i] === '1')one++;
        else zero++;
    }
    cur = input[i];
}

console.log(Math.min(zero, one));