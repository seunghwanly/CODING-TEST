// function solution(d, budget) {
//     var answer = 0;

//     // sort
//     d.sort((a, b) => a - b);
//     if (budget < d[0]) return 0;
//     else {
//         for (let i = 0; i < d.length; ++i) {
//             let sum = d[i];
//             let cnt = 1;
//             for (let j = i + 1; j < d.length; ++j) {
//                 if (sum + d[j] <= budget) {
//                     sum += d[j];
//                     cnt++;
//                 } else break;
//             }
//             // check
//             if (answer < cnt) answer = cnt;
//         }
//     }

//     return answer;
// }
const solution = (d, budget) => {
    let answer = 0;
    let sum = 0;
    d.sort((a,b) => a - b).forEach(element => {
        sum += element;
        if(sum <= budget) answer++;
    });
    return answer;
}

console.log(solution([1, 2, 3, 5, 4], 9));
console.log(solution([2, 2, 3, 3], 10));