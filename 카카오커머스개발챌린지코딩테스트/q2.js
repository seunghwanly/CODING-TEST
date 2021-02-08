function solution(m, v) {
    var answer = 0;

    let matrix = [
        {
            level: 1,
            leftOver: m
        }
    ]; // matrix[level][leftover]

    let currentLevel = 0;

    v.forEach(comingBlock => {
        // first block
        if (matrix[currentLevel].leftOver === m) matrix[currentLevel].leftOver -= comingBlock;
        // 2nd ~
        else {
            // block > leftOVer
            if (comingBlock > matrix[currentLevel].leftOver) {
                let minLeftOver = { index: 0, leftOver: m };
                // check leftOvers
                matrix.forEach((levelLeftOver, levelIndex) => {
                    if (comingBlock <= levelLeftOver && levelLeftOver < minLeftOver.leftOver) {
                        minLeftOver.index = levelIndex;
                        minLeftOver.leftOver = levelLeftOver;
                    }
                })
                if (minLeftOver.leftOver <= matrix[currentLevel].leftOver) {
                    matrix[minLeftOver.index].leftOver -= comingBlock;
                } else {
                    currentLevel++;
                    matrix[currentLevel] = {
                        level: currentLevel + 1,
                        leftOver: m - comingBlock
                    };
                }
            }
            // block === leftOver
            // block < leftOver
            else {
                matrix[currentLevel].leftOver -= comingBlock;
            }
        }
    });

    answer = matrix.length;

    return answer;
}

console.log(solution(4, [2, 3, 1]));
console.log(solution(4, [3, 2, 3, 1]));