// function solution(n) {
//     var answer = [];

//     // into tree structure
//     let tree = [];
//     let maxNode = 0;
//     for (let i = 1; i <= n; ++i) maxNode += i;
//     let cnt = 1;
//     for (let i = 1; i <= n; ++i) {
//         for (let j = 0; j < i; ++j) {
//             let childern = [];
//             if (cnt + i + 1 <= maxNode) {
//                 childern = [cnt + i, cnt + i + 1];
//             }
//             let parent = [];
//             if (cnt > 1) {
//                 // left-max
//                 if ((cnt - j) === cnt) parent = [(cnt - j) - (i - 1)];
//                 // right-max
//                 else if ((cnt - j + i - 1) === cnt) parent = [cnt - j - 1];
//                 // middle
//                 else parent = [(cnt - j) - (i - 1), cnt - j - i + 2];
//             }
//             tree.push({
//                 id: cnt,
//                 height: i,
//                 childern: childern,
//                 parent: parent,
//                 val: 0,
//                 side: (cnt - j) === cnt ? 'left' : j + 1 === i ? 'right' : null
//             });
//             cnt++;
//         }
//     }
//     // push value
//     const fillValue = (tree, id, value) => {
//         // 다시해

//     }

//     // fill tree
//     fillValue(tree, 1, 1);

//     return tree.map(e => e.val);
// }


const solution = (n) => {
    // list for result
    let list = [];
    // flag start from index 0
    let currentIndex = 0;
    let currentHeight = 1;
    let currentCount = 1;
    let currentDirectionIndex = 2; // 2: left_side | 1: below | 0:right_side
    // loop n, n-1, n-2, n-3, ...
    for (let i = n; i > 0; --i) {

        for (let j = i; j > 0; --j) {

            // set value
            list[currentIndex + 1] = currentCount;
            currentCount++;

            // turn direction
            if (j !== 1) {
                // check direction
                if (currentDirectionIndex === 2) {
                    // left_side
                    currentIndex += currentHeight;
                    currentHeight += 1;
                } else if (currentDirectionIndex === 1) {
                    // below
                    currentIndex += 1;
                } else {
                    // right_side
                    currentIndex -= currentHeight;
                    currentHeight -= 1;
                }
            } else {
                // check direction
                if (currentDirectionIndex === 2) {
                    // left_side >>> to below
                    currentIndex += 1;
                } else if (currentDirectionIndex === 1) {
                    // below >>> to right_side
                    currentIndex -= currentHeight;
                    currentHeight -= 1;
                } else {
                    // right_side >>> to left_side
                    currentIndex += currentHeight;
                    currentHeight += 1;
                }
            }
        }
        if (currentDirectionIndex > 0) currentDirectionIndex--;
        else currentDirectionIndex = 2;
    }

    return list.slice(1, list.length);
}

// console.log(solution(4));
console.log(solution(5));