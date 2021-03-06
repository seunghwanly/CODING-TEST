function solution(dartResult) {
    let answer = [];
    let map = [];
    let pattern = /\d(\d?)\D([*,#]?)/g;
    let array = dartResult.match(pattern);
    // classification
    array.forEach(element => {
        let number = element.match(/\d/g).reduce((a, b) => a + b);
        let bonus = element.match(/[A-Z]/g).reduce((a, b) => a + b);
        let option = element.match(/[*,#]?/g).reduce((a, b) => a + b);
        map.push({
            score: number,
            bonus: bonus,
            option: option
        });
    });
    // into number
    map.forEach(element => {
        let temp;
        switch (element.bonus) {
            case 'S':
                temp = parseInt(element.score); break;
            case 'D':
                temp = Math.pow(element.score, 2); break;
            case 'T':
                temp = Math.pow(element.score, 3); break;
            default:
                break;
        }
        answer.push(temp);
    });
    // add option
    map.forEach((element, index) => {
        if (element.option === '*') {
            answer[index - 1] *= 2;
            answer[index] *= 2;
        } else if (element.option === '#') {
            answer[index] *= -1;
        }
    })
    return answer.reduce((a,b) => a+b);
}

//console.log(solution('1S2D*3T'));
console.log(solution('1D2S#10S'));