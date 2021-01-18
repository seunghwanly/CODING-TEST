function solution(n)
{
    var answer = 0;

    String(n).split('').forEach(element => {
        answer += Number.parseInt(element);
    });

    return answer;
}

console.log(solution(123));