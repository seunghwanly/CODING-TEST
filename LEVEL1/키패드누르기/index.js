function solution(numbers, hand) {
    var answer = '';

    let keyPad = [
        { key: '*', hand: 'l', pos_x: 0, pos_y: 0 },
        { key: 7, hand: 'l', pos_x: 0, pos_y: 1 },
        { key: 4, hand: 'l', pos_x: 0, pos_y: 2 },
        { key: 1, hand: 'l', pos_x: 0, pos_y: 3 },
        { key: '#', hand: 'r', pos_x: 2, pos_y: 0 },
        { key: 9, hand: 'r', pos_x: 2, pos_y: 1 },
        { key: 6, hand: 'r', pos_x: 2, pos_y: 2 },
        { key: 3, hand: 'r', pos_x: 2, pos_y: 3 },
        { key: 0, hand: 'c', pos_x: 1, pos_y: 0 },
        { key: 8, hand: 'c', pos_x: 1, pos_y: 1 },
        { key: 5, hand: 'c', pos_x: 1, pos_y: 2 },
        { key: 2, hand: 'c', pos_x: 1, pos_y: 3 },
    ];

    let currLeft = { pos_x: 0, pos_y: 0 };
    let currRight = { pos_x: 2, pos_y: 0 };

    const pressL = (press) => {
        answer += 'L';
        currLeft.pos_x = press.pos_x;
        currLeft.pos_y = press.pos_y;
    }
    const pressR = (press) => {
        answer += 'R';
        currRight.pos_x = press.pos_x;
        currRight.pos_y = press.pos_y;
    }
    
    numbers.forEach((key) => {

        let toPress = keyPad.find((item) => item.key === key);
        
        if (toPress.hand === 'l') {
            pressL(toPress);
        } else if (toPress.hand === 'r') {
            pressR(toPress);
        } else {
            if (Math.abs(currLeft.pos_x - toPress.pos_x) + Math.abs(currLeft.pos_y - toPress.pos_y)
                < Math.abs(currRight.pos_x - toPress.pos_x) + Math.abs(currRight.pos_y - toPress.pos_y)) {
                pressL(toPress);
            } else if (Math.abs(currLeft.pos_x - toPress.pos_x) + Math.abs(currLeft.pos_y - toPress.pos_y)
                > Math.abs(currRight.pos_x - toPress.pos_x) + Math.abs(currRight.pos_y - toPress.pos_y)) {
                pressR(toPress);
            } else {
                if (hand === 'right') {
                    pressR(toPress);
                } else {
                    pressL(toPress);
                }
            }
        }
    });

    return answer;
}

console.log(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"));
console.log(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], 'left'));
console.log(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], 'right'));