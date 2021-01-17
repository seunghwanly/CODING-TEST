function solution(progresses, speeds) {
    var answer = [];
    let daysLeftOver = [];
    // init leftOver
    for (let i = 0; i < progresses.length; ++i) {
        let leftPercentage = (100 - progresses[i]);
        let leftDays = Math.ceil(leftPercentage / speeds[i]);
        daysLeftOver.push(leftDays);
    }
    // console.log(daysLeftOver);
    let timer = 0;

    while (true) {
        if (daysLeftOver.length === 0) break;
        timer++;
        let cnt = 0;
        for (let i = 0; i < daysLeftOver.length; ++i) {
            if (timer >= daysLeftOver[i]) {
                cnt++;
            } else break;
        }
        for (let i = 0; i < cnt; ++i) daysLeftOver.shift();
        if (cnt != 0) {
            answer.push(cnt);
            cnt = 0;
        }
    }


    return answer;
}

console.log(solution([93, 30, 55], [1, 30, 5]));
console.log(solution([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1]));