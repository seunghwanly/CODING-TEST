function solution(numbers) {

    // 내림차순
    numbers.sort((a, b) => b - a);

    // into list
    let units = [];         // 1
    let tens = [];          // 10
    let hundreds = [];      // 100
    let thousands = [];     // 1000

    numbers.forEach(element => {
        switch (element.toString().length) {
            case 1:
                units.push(element);
                break;
            case 2:
                tens.push(element);
                break;
            case 3:
                hundreds.push(element);
                break;
            case 4:
                thousands.push(element);
                break;
            default:
                break;
        }
    });

    let answerList = [];

    // check front
    for (let i = 0; i < numbers.length; ++i) {
        // get element
        let tempList = [];
        if (units[0] !== undefined) tempList.push({ arr: 'unit', val: units[0] });
        if (tens[0] !== undefined) tempList.push({ arr: 'tens', val: parseInt(tens[0].toString()[0]) });
        if (hundreds[0] !== undefined) tempList.push({ arr: 'hundred', val: parseInt(hundreds[0].toString()[0]) });
        if (thousands[0] !== undefined) tempList.push({ arr: 'thousand', val: parseInt(thousands[0].toString()[0]) });

        // find Max
        const findMax = (arr) => {
            if (arr.length === 0) return;
            let max = arr[0].val;
            let maxKey = arr[0].arr;

            for (let i = 0; i < arr.length; ++i) {
                // console.log(arr[i].val, max)
                if (arr[i].val > max) {
                    maxKey = arr[i].arr;
                    max = arr[i].val;
                } else if (arr[i].val === max) {
                    if (arr[i].arr === 'tens') {
                        if (tens[0].toString()[1] > max) { maxKey = arr[i].arr; max = arr[i].val; }
                    } else if (arr[i].arr === 'hundred') {
                        if (hundreds[0].toString()[1] > max) { maxKey = arr[i].arr; max = arr[i].val; }
                        if (hundreds[0].toString()[2] > max) { maxKey = arr[i].arr; max = arr[i].val; }
                    } else if (arr[i].arr === 'thousand') {
                        if (thousands[0].toString()[1] > max) { maxKey = arr[i].arr; max = arr[i].val; }
                        if (thousands[0].toString()[2] > max) { maxKey = arr[i].arr; max = arr[i].val; }
                        if (thousands[0].toString()[3] > max) { maxKey = arr[i].arr; max = arr[i].val; }
                    }
                }
            }
            return maxKey;
        }

        let maxListName = '';

        // check tempList
        if (tempList.length === 1) maxListName = tempList[0].arr;
        else maxListName = findMax(tempList);

        // push to answer
        if (maxListName === 'unit') answerList.push(units.shift());
        else if (maxListName === 'tens') answerList.push(tens.shift());
        else if (maxListName === 'hundred') answerList.push(hundreds.shift());
        else answerList.push(thousands.shift());
    }

    if(answerList.every((val) => val === 0)) return '0';

    return answerList.join('');
}

const newSol = (numbers) => {
    numbers.sort((a,b) => ''+a+b>''+b+a ? -1 : 1)

    if(numbers.every(val => val === 0)) return '0';

    return numbers.reduce((acc, curr) => acc+curr, '')
}
// console.log(solution([500, 11, 12, 13]));
// console.log(solution([10, 101]));
// console.log(solution([40, 403]));
// console.log(solution([6, 10, 2]));
// console.log(solution([3, 30, 31, 33]));
// console.log(solution([3, 30, 34, 5, 9]));
// console.log(solution([10, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]));
// console.log(solution([0,0,0,0]));
// console.log(solution([40,404]));

console.log(newSol([0,0,0,0]));
console.log(newSol([40,404]));
