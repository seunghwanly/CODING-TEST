function solution(needs, r) {
    var answer = 0;

    let numbers = needs[0].length;
    // 부품 검사
    // let parts = new Array(numbers).fill(0, 0, numbers);

    let parts = [];
    for (let i = 0; i < numbers; ++i) {
        parts.push(
            {
                idx: i,
                val: 0
            }
        )
    }

    // 조사
    needs.forEach(array => {
        array.forEach((value, index) => {
            if (value === 1) {
                parts[index].val++;
            }
        })
    })


    parts.sort((a, b) => b.val - a.val);

    // r
    let robots = [];
    for (let l = 0; l < r; ++l) {
        robots.push(parts[l].idx);
    }

    // 완제품 조사
    needs.forEach((array) => {
        let cnt = 0;
        let oneCount = 0;
        array.forEach((value, index) => {
            if (value === 1 && robots.includes(index)) {
                cnt++;
            }
            if (value === 1) {
                oneCount++;
            }
        })

        if (cnt === oneCount) {
            answer++;
        }
    })

    return answer;
}

console.log(solution(
    [
        [1, 0, 0],      // 0 : 0
        [1, 1, 0],      // 1 : 0, 1
        [1, 1, 0],      // 2 : 0, 1,
        [1, 0, 1],      // 3 : 0, 2
        [1, 1, 0],      // 4 : 0, 1
        [0, 1, 1]       // 5 : 1, 2
    ], 2
));