const input = require("fs")
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

// 전기 요금을 계산하는 함수
function calculateElectricityBill(usage) {
  let cost = 0;
  if (usage >= 1000001) {
    cost += 7 * (usage - 1000000);
    usage = 1000000;
  }
  if (usage >= 10000) {
    cost += 5 * (usage - 10000);
    usage = 10000;
  }
  if (usage >= 100) {
    cost += 3 * (usage - 100);
    usage = 100;
  }
  cost += 2 * usage;
  return cost;
}

input.forEach((v) => {
  let [A, B] = v.split(" ").map(Number);
  if (A === 0 && B === 0) return;

  let left = 0;
  let right = 1e9;
  let next;

  // 전체 사용량을 이분 탐색으로 찾기
  while (left <= right) {
    let middle = Math.floor((left + right) / 2);
    let part = calculateElectricityBill(middle);

    if (part > A) {
      right = middle - 1;
    } else if (part < A) {
      left = middle + 1;
    } else {
      next = middle;
      break;
    }
  }

  let middle = next;
  let l = 0;
  let r = Math.floor(middle / 2);
  let result;

  // 상근과 친구의 요금 차이를 맞추기 위한 이분 탐색
  while (l <= r) {
    let m = Math.floor((l + r) / 2);
    let o = middle - m;
    let p = calculateElectricityBill(m);
    let po = calculateElectricityBill(o);
    //console.log(p, po);
    if (Math.abs(p - po) === B) {
      result = p;
      break;
    } else if (Math.abs(p - po) > B) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  console.log(result);
});
