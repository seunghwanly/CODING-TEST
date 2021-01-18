function solution(n) {
    var answer = [];
    String(n).split('').forEach(element => answer.push(parseInt(element)));
    answer.reverse();
    return answer;
}
console.log(solution(12345));