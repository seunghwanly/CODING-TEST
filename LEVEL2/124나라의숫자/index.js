function solution(n) {
    var answer = '';
    let remainder = -1;

    while(n>0) {
        remainder = n % 3;
        n = Number.parseInt(n/3);
        switch(remainder) {
            case 1:
                answer += '1';
                break;
            case 2:
                answer += '2';
                break;
            case 0:
                answer += '4';
                n--;
                break;
        }
    }
    answer = answer.split('').reverse().join('');

    return answer;
}

console.log(solution(4));