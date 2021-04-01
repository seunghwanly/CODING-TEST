function solution(clothes) {
    var answer = 0;

    let map = [];

    // [ name, kind ] to map
    clothes.forEach(element => {
        let name = element[0];
        let kind = element[1];

        let index = map.findIndex((value, index) => value.kind === kind);
        if (index === -1) {
            map.push(
                {
                    'kind': kind,
                    'names': [name]
                }
            );
        } else {
            map[index].names.push(name);
        }
    });

    let res = 1;
    map.forEach(e => res *= (e.names.length + 1));
    return res - 1;

    //console.log(map);

    const calculateCombination = (n, k) => {
        let molecule = 1;
        for (let i = 0; i < k; ++i) {
            molecule *= (n - i);
        }
        let denominator = 1;
        for (let i = k; i >= 1; --i) {
            denominator *= i;
        }
        return Math.floor(molecule / denominator);
    }

    /**
     *  N개의 집단, K개씩 뽑기(1, ..., N)
     *  K가 1일 경우 모든 갯수
     *  K가 1이 아닐 경우 
     *      n C k - SUM( 각 배열의 길이 C k)
     */
    let n = 0;
    map.forEach((element) => { n += element.names.length });

    for (let i = 1; i <= map.length; ++i) {
        if (i === 1) {
            // add all length
            answer += n;
        }
        else {
            let sumofArrays = 0;
            map.forEach((element) => {
                if (element.names.length >= i) {
                    // 한 집단에서 k개를 모두 뽑을 경우
                    sumofArrays += calculateCombination(element.names.length, i);
                    // 한 집단에서 (k-1)개를 모두 뽑을 경우
                    for(let k = i - 1; k > 1; --k) {
                        sumofArrays += calculateCombination(element.names.length, k) * (n - element.names.length);
                    }
                }
            })
            answer += (calculateCombination(n, i) - sumofArrays);
        }
    }

    return answer;
}

console.log(solution([["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]]));
console.log(solution([["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]));

console.log(solution([
    ["a", "aa"],
    ["b", "aa"],
    ["c", "aa"],
    ["aa", "bb"],
    ["bb", "bb"],
    ["c_c", "bb"],
    ["aaa", "cc"],
    ["bbb", "cc"],
    ["ccc", "cc"]
]));    // 63
console.log(solution([
    ["a", "a"],
    ["b", "b"],
    ["c", "c"]
])); // 7