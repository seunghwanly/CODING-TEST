function solution(n, m) {
    
    const getGCD = (a, b) => {
        if(b === 0) return a;
        else return getGCD(b, a%b);
    }

    return [
        getGCD(n,m), n * m / getGCD(n,m)
    ];
}

console.log(solution(3, 12));
console.log(solution(2, 5));