const fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const N = parseInt(input[0]);
const arr = input.slice(1).map(line => line.split(''));

let heart = [0, 0];

for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
        if (arr[i][j] === '*') {
            heart = [i + 1, j]; // 심장은 가장 첫 번째 `*`의 바로 아래에 위치
            break;
        }
    }
    if (heart[0] !== 0) break;
}

let left_arm = 0, right_arm = 0, waist = 0, left_leg = 0, right_leg = 0;

// 왼쪽 팔 길이
for (let j = heart[1] - 1; j >= 0; j--) {
    if (arr[heart[0]][j] === '*') {
        left_arm++;
    } else {
        break;
    }
}

// 오른쪽 팔 길이
for (let j = heart[1] + 1; j < N; j++) {
    if (arr[heart[0]][j] === '*') {
        right_arm++;
    } else {
        break;
    }
}

// 허리 길이
for (let i = heart[0] + 1; i < N; i++) {
    if (arr[i][heart[1]] === '*') {
        waist++;
    } else {
        break;
    }
}

// 왼쪽 다리 길이
for (let i = heart[0] + waist + 1; i < N; i++) {
    if (arr[i][heart[1] - 1] === '*') {
        left_leg++;
    } else {
        break;
    }
}

// 오른쪽 다리 길이
for (let i = heart[0] + waist + 1; i < N; i++) {
    if (arr[i][heart[1] + 1] === '*') {
        right_leg++;
    } else {
        break;
    }
}

console.log(`${heart[0] + 1} ${heart[1] + 1}`);
console.log(`${left_arm} ${right_arm} ${waist} ${left_leg} ${right_leg}`);
