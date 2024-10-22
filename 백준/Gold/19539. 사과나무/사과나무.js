const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n");

let N = input[0];
let arr = input[1].split(' ').map(Number);

let two = 0;
let one = 0;

arr.forEach((v) => {
  if (v % 2 === 1) {
    one++;
  }
  two += Math.floor(v / 2); // Accumulate the "twos" from each number
});

// Now we need to check if it's possible to equalize two and one
if (two >= one && (two - one) % 3 === 0) {
  console.log("YES");
} else {
  console.log("NO");
}
