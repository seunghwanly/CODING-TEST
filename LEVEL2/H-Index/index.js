function solution(citations) {

    if (citations.every((element) => element === citations[0])) return citations[0];
    // sort
    citations.sort((a, b) => a - b);

    let hIndex = 0, upCount = 0, downCount = 0;
    // for loop until medium
    for (let i = citations[0]; i < citations[citations.length - 1]; ++i) {

        if (i === 0) continue;
        citations.forEach(element => {
            if (element >= i) upCount++;
            if (element <= i) downCount++;
            // console.log(i, element, upCount, downCount);
        });
        if (upCount >= i && downCount <= i) {
            if (hIndex < i) hIndex = i;
        }
        upCount = downCount = 0;
    }
    if (hIndex === 0) hIndex = citations.length;
    return hIndex;
}

// console.log(solution([3, 0, 6, 1, 5])); // 3
// console.log(solution([10, 8, 5, 4, 3]));// 4
// console.log(solution([25, 8, 5, 3, 3]));// 3
// console.log(solution([6, 6, 6, 6, 6, 1]));// 5
// console.log(solution([10, 11, 12, 13])); // 4
console.log(solution([0]));