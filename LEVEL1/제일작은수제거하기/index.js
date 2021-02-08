function solution(arr) {
    let min = Number.MAX_SAFE_INTEGER;
    arr.forEach(element => {
        if (element < min) min = element;
    });

    arr = arr.filter((e) => e > min);
    if (arr.length === 0) arr.push(-1);
    return arr;
}

console.log(solution([4, 3, 2, 1]));
console.log(solution([10]));