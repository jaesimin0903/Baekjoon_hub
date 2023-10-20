var list = [];

function solution(numbers, target) {
    var answer = 0;
    dfs(numbers, 0, 0,target);  // i와 초기 합계를 인수로 전달
    answer = list.length;  // 목표 합계를 달성하는 경우의 수를 반환
    return answer;
}

function dfs(numbers, i, sum, target) {
    if (i === numbers.length) {
        if (sum === target) {
            list.push(1);  // 목표 합계를 달성하면 list에 1을 추가
        }
        return;
    }
    dfs(numbers, i + 1, sum + numbers[i], target);  // + dfs
    dfs(numbers, i + 1, sum - numbers[i], target);  // - dfs
}
