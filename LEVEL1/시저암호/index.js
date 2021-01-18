function solution(s, n) {
    var answer = '';

    s.split('').forEach(element => {
        if (65 <= element.charCodeAt(0) && element.charCodeAt(0) <= 90)
            answer += String.fromCharCode(element.charCodeAt(0) + n > 90 ? element.charCodeAt(0) + n - 90 + 64 : element.charCodeAt(0) + n);
        else if (97 <= element.charCodeAt(0) && element.charCodeAt(0) <= 125)
            answer += String.fromCharCode(element.charCodeAt(0) + n > 122 ? element.charCodeAt(0) + n - 122 + 96 : element.charCodeAt(0) + n);
        else
            answer += element;
    });

    return answer;
}

console.log(solution("AB", 1));
console.log(solution("z", 1));
console.log(solution("a B z", 4));