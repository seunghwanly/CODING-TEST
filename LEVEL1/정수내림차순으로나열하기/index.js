function solution(n) {
    return parseInt(n.toString().split('').sort((a, b) => b - a).join(''));
}

console.log(solution(118372))