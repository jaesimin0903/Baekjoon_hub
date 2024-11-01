const input = require('fs')
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g,"")
  .trim()
  .split("\n")
  .map(String);

let str = input[0];
let target = input[1];
let stack = [];
for(let i =0;i<str.length;i++){
  stack.push(str[i]);

  if(stack.length >= target.length && stack.slice(-target.length).join('') === target){
    stack.length -=target.length;
  }
}

const answer = stack.join('');

console.log(answer.length > 0 ? answer : "FRULA");