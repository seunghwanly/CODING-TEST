function solution(N, stages) {

    var answer = [];

    for (let i = 1; i <= N; ++i) {
        let complete = stages.filter(val => val > i);
        let tried = stages.filter(val => val >= i);
        let fail = (tried.length - complete.length) / tried.length;
        answer.push({ 'stage': i, 'failure': fail });
    }
    
    answer.sort((a, b) => b.failure - a.failure);

    return answer.map(val => val.stage);
}

console.log(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]));
console.log(solution(4, [4,4,4,4,4]));