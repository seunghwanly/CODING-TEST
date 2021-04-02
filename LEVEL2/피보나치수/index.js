const fibonacci = (n) => {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}   // very very inefficient : O(2^n)

const memoizationFibonacci = (n, memo = []) => {
    let result = 0;
    if (memo[n] !== undefined) {
        return memo[n];
    }
    if (n <= 1) {
        result = n;
    }
    else {
        result = memoizationFibonacci(n - 1, memo) + memoizationFibonacci(n - 2, memo);
    }
    memo[n] = result;
    return result;
}   // O(2n + 1)

const bottomupFibonacci = (n) => {
    if (n <= 1) {
        return n;
    }
    let bottomupList = [];
    bottomupList[0] = 0;
    bottomupList[1] = 1;
    // for loop to n
    for (let i = 2; i <= n; ++i) {
        bottomupList[i] = bottomupList[i - 1] % 1234567 + bottomupList[i - 2] % 1234567;
    }
    return bottomupList[n];
}   // O(n) : travel only once

function solution(n) {
    var answer = 0;

    // answer = fibonacci(n) % 1234567;
    // answer = memoizationFibonacci(n) % 1234567;
    answer = bottomupFibonacci(n) % 1234567;

    return answer;
}

console.log(solution(3));
console.log(solution(5));