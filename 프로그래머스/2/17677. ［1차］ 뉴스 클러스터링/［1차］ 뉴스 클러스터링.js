function solution(str1, str2) {
    str1 = str1.toUpperCase();
    str2 = str2.toUpperCase();
    
    let multiset1 = [];
    let multiset2 = [];

    // str1에서 두 글자씩 끊어서 멀티셋에 추가
    for (let i = 0; i < str1.length - 1; i++) {
        let pair = str1.slice(i, i + 2);
        if (/^[a-zA-Z]{2}$/.test(pair)) {
            multiset1.push(pair);
        }
    }

    // str2에서 두 글자씩 끊어서 멀티셋에 추가
    for (let i = 0; i < str2.length - 1; i++) {
        let pair = str2.slice(i, i + 2);
        if (/^[a-zA-Z]{2}$/.test(pair)) {
            multiset2.push(pair);
        }
    }

    // 교집합과 합집합 계산
    let intersection = [];
    let union = [];

    let map1 = new Map();
    let map2 = new Map();

    // multiset1 요소들의 등장 횟수를 map1에 저장
    multiset1.forEach(e => {
        map1.set(e, (map1.get(e) || 0) + 1);
    });

    // multiset2 요소들의 등장 횟수를 map2에 저장
    multiset2.forEach(e => {
        map2.set(e, (map2.get(e) || 0) + 1);
    });

    // 합집합과 교집합 계산
    let allKeys = new Set([...map1.keys(), ...map2.keys()]);
    
    allKeys.forEach(key => {
        let count1 = map1.get(key) || 0;
        let count2 = map2.get(key) || 0;

        // 교집합은 두 집합에서 중복된 최소값
        let intersectionCount = Math.min(count1, count2);
        for (let i = 0; i < intersectionCount; i++) {
            intersection.push(key);
        }

        // 합집합은 두 집합의 최대 등장 횟수
        let unionCount = Math.max(count1, count2);
        for (let i = 0; i < unionCount; i++) {
            union.push(key);
        }
    }); 

    // 자카드 유사도 계산
    if (union.length === 0) return 65536; // 둘 다 공집합인 경우
    return Math.floor((intersection.length / union.length) * 65536);
}
