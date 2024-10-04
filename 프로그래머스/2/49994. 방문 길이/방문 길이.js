function solution(dirs) {
    var answer = 0;
    
    let set = new Set();
    
    let y = 0;
    let x = 0;
    //set.add(`${y},${x}`);  // 좌표를 문자열로 변환하여 추가
    for(let i = 0; i < dirs.length; i++) {
        if (dirs[i] == 'U' && y >-5) {  // 경계 체크 추가
            set.add(`${y-1},${x},${y},${x}`);
            y--;
        } else if (dirs[i] == 'D' && y < 5) {
            set.add(`${y},${x},${y+1},${x}`); y++;
        } else if (dirs[i] == 'L' && x > -5) {
            set.add(`${y},${x-1},${y},${x}`);x--;
        } else if (dirs[i] == 'R' && x < 5) {
            set.add(`${y},${x},${y},${x+1}`);x++;
        }
    }
    //console.log(set);
    return set.size;  // 시작점 제외
}
