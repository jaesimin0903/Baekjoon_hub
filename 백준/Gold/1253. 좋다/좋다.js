const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n");

let n = Number(input[0]);
let array = input[1].split(' ').map(Number);
array.sort((a, b) => a - b);
let count = 0;

for (let i = 0; i < n; i++) {
  let x = array[i];
  for (let j = 0; j < n; j++) {
    if (i === j) continue;

    let start = 0;
    let end = n - 1;
    let check = false;

    while (start <= end) {
      let mid = Math.floor((start + end) / 2);

      if (x === array[j] + array[mid]) {
        let m = mid;

        // 왼쪽 방향으로 인덱스 조정
        while (i === m || j === m) {
          if (m === 0) break;
          m -= 1;
        }

        if ((i !== m && j !== m) && (x === array[j] + array[m])) {
          count += 1;
          check = true;
          break;
        }

        m = mid;

        // 오른쪽 방향으로 인덱스 조정
        while (i === m || j === m) {
          if (m === n - 1) break;
          m += 1;
        }

        if ((i !== m && j !== m) && (x === array[j] + array[m])) {
          count += 1;
          check = true;
          break;
        }
        break;

      } else if (x > array[j] + array[mid]) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    if (check) break;
  }
}

console.log(count);
