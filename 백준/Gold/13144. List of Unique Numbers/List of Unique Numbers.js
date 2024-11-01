const input = require('fs')
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g,"")
  .trim()
  .split("\n")
  .map(String);

let N = Number(input[0]);
let arr = input[1].split(' ').map(Number);

let left = 0;
let right = 0;
let set = new Set();
let answer = 1;
set.add(arr[0]);
while(!(left > right || (left === right && right === N -1)) ){
  //console.log(arr.join('').substring(left, right+1))
  if(right + 1 < N){
    if(set.has(arr[right+1])){
      answer += set.size;
      set.delete(arr[left]);
      if(left === right){
        right++;
        left++;
        set.add(arr[left]);
      }else left++;
    }else{
      set.add(arr[++right]);
      
    }
  }else{
    answer += set.size;
    set.delete(arr[left++]);
  }
}

console.log(answer);