function solution(n) {
    return Number.isSafeInteger(Math.sqrt(n)) ? Math.pow(Math.sqrt(n)+1, 2) : -1;
    
}

console.log(solution(121));
console.log(solution(3));