function solution(x) {
    let sum = 0;
    let stringX = x.toString().split('');
    stringX.forEach(char => {
        sum += Number.parseInt(char);
    });

    return x % sum === 0 ? true : false;
}

console.log(solution(10));
console.log(solution(12));
console.log(solution(11));
console.log(solution(13));