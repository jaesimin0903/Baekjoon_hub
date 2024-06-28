const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let N = parseInt(input[0]);
let heights = input.slice(1).map(Number);

let stack = [];
let ans = 0;

for (let i = 0; i < N; i++) {
    while (stack.length > 0 && stack[stack.length - 1] <= heights[i]) {
        stack.pop();
    }
    ans += stack.length;
    stack.push(heights[i]);
}

console.log(ans);
