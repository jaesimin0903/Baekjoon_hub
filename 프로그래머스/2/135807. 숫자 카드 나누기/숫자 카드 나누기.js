function gcd(a, b) {
    while (b != 0) {
        let temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

function findGCD(arr) {
    return arr.reduce((acc, num) => gcd(acc, num));
}

function isDivisibleByAll(arr, num) {
    return arr.every(value => value % num === 0);
}

function isNotDivisibleByAny(arr, num) {
    return arr.every(value => value % num !== 0);
}

function solution(arrayA, arrayB) {
    let gcdA = findGCD(arrayA);
    let gcdB = findGCD(arrayB);
    
    let candidate1 = 0, candidate2 = 0;
    
    // 조건 1: 철수가 가진 카드들의 GCD가 영희의 카드들을 나눌 수 없는지 확인
    if (isNotDivisibleByAny(arrayB, gcdA)) {
        candidate1 = gcdA;
    }
    
    // 조건 2: 영희가 가진 카드들의 GCD가 철수의 카드들을 나눌 수 없는지 확인
    if (isNotDivisibleByAny(arrayA, gcdB)) {
        candidate2 = gcdB;
    }
    
    // 두 조건 중 더 큰 값을 반환, 없으면 0 반환
    return Math.max(candidate1, candidate2);
}
