function solution(arr1, arr2) {
    var answer = [];
    const len = arr1.length;
    for (let i = 0; i < len; ++i) {
        const temp1 = arr1.shift();
        const temp2 = arr2.shift();
        let tempAns = [];
        temp1.forEach((val, idx) => {
            tempAns.push(val + temp2[idx]);
        });
        answer.push(tempAns);
    }

    return answer;
}

console.log(solution([[1, 2], [2, 3]], [[3, 4], [5, 6]]));
console.log(solution([[1], [2]], [[3], [4]]));