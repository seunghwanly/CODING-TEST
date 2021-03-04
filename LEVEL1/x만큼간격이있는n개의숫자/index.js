function solution(x, n) {
    return [...Array(n).keys()].map(e => (e+1) * x);
}

console.log(solution(2, 5));
console.log(solution(4, 3));
console.log(solution(-4, 2));