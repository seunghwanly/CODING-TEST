function solution(brown, yellow) {
    var answer = [];

    let mul = brown + yellow;

    let width = 3;
    let height = 3;

    let list = [];

    const divisors = (n) => {
        for (let i = 2; i < n; ++i) {
            if (n % i == 0) {
                list.push(i);
            }
        }
    }
    divisors(mul);

    let breakOuter = false;
    for (let i = list.length; i > -1; --i) {
        for (let j = i; j > -1; --j) {
            if (list[i] * list[j] === mul &&
                yellow === (list[i] - 2) * (list[j] - 2)) {
                width = list[i];
                height = list[j];
                breakOuter = true;
                break;
            }
        }
        if (breakOuter) break;
    }

    answer.push(width);
    answer.push(height);

    return answer;
}

console.log(solution(10, 2));
console.log(solution(8, 1));
console.log(solution(12, 4));
console.log(solution(24, 24));
console.log(solution(50, 22));