function solution(v) {
    let y = [];
    let x = [];
    v.forEach(arr => {
        if (!y.includes(arr[0])) y.push(arr[0]);
        else y = y.filter((v) => v !== arr[0]);
        if (!x.includes(arr[1])) x.push(arr[1]);
        else x = x.filter((v) => v !== arr[1]);
    });
    var answer = [y[0], x[0]];
    return answer;
}

console.log(solution([[1, 4], [3, 4], [3, 10]]));