function solution(s) {
    var answer = '';

    let array = s.split(' ');

    for (let i = 0; i < array.length; ++i) {
        for (let j = 0; j < array[i].length; ++j) {
            (j % 2 === 0) ? answer += array[i][j].toUpperCase() : answer += array[i][j].toLowerCase();
        } 
        if(i < array.length - 1) answer += " ";
    }
    return answer;
}
// function solution(s) {
//     let answer = '';
//     let count = 0;
//     for (let i = 0; i < s.length; ++i) {
//         if (count % 2 === 0) { 
//             answer += String(s[i]).toUpperCase(); 
//             count++; 
//         }
//         else if (count % 2 === 1) { 
//             answer += String(s[i]).toLowerCase();
//             count++; 
//         }
//         else { 
//             if(i < s.length - 1)
//                 answer += ' '; 
//             count = 0; 
//         }
//     }
//     return answer;
// }

console.log(solution('try hello world'));