// function solution(number, k) {
//     // for sorted list
//     const arr = number.split('');
//     const sortedList = arr.sort((a, b) => a - b).filter((val, idx) => arr.indexOf(val) === idx).filter((val, idx) => idx < k);
//     const maxItem = sortedList.pop();

//     // for main Stack
//     const numberStack = number.split('');

//     let candidateStacks = [];
//     let count = 0;

//     // loop - Greedy
//     for (let i = 0; i < numberStack.length - 1; ++i) {

//         let tempStack = [];
//         let pushedIndex = [];
//         // sortedList not includes head
//         if (!sortedList.includes(numberStack[i])) {
//             // make candidates
//             // tempStack.length < numberStack.length - k
//             for (let l = i; l < numberStack.length; ++l) {
//                 // push head
//                 tempStack.push(numberStack[i]); // head
//                 pushedIndex.push(i);

//                 for (let j = l + 1; j < numberStack.length - 1; ++j) {
//                     if (j - tempStack.length === k) {
//                         tempStack.push(numberStack.splice(j, numberStack.length - 1).join(''));
//                     } else {
//                         // push others
//                         if (!sortedList.includes(numberStack[j]) || maxItem === numberStack[j]) {
//                             if (!pushedIndex.includes(j)) {
//                                 tempStack.push(numberStack[j]);
//                                 pushedIndex.push(j);
//                             }
//                         }
//                     }

//                 }
//                 if (!candidateStacks.includes(tempStack.join(''))) {
//                     candidateStacks.push(tempStack.join(''));
//                     tempStack = [];
//                     pushedIndex = [];
//                 }
//             }

//         } else continue;
//     }
//     // among candidates
//     let currentMax = '0';
//     candidateStacks.forEach(element => {
//         if (parseInt(element) > parseInt(currentMax)) currentMax = element;
//     })
//     console.log(candidateStacks);
//     return currentMax;
// }

function solution(number, k) {
    /**
     *  stack을 이용한 풀이방법
     *  각 원소별로 비교를 해주는데, 현재 뽑은 원소가 stack안에 저장되어있는 값들과 비교
     *  현재 원소 vs stack[top] 을 진행해준다.
     * 
     *  ! 스택을 사용하기 때문에 index는 지켜진다. 
     */
    let stack = [];
    // 각 원소마다 진행 !
    number.split('').forEach((element) => {
        /**
         *  1. 무조건 stack에 push를 한다.
         *  2. while loop {
         *          element와 stack[top] 비교
         *          stack에서 빼는 순간(=pop()) -> k -= 1;
         *     }
         *  3. k를 모두 소진했다면 그냥 push
         */
        while (k > 0 && stack[stack.length - 1] < element) {
            stack.pop(); k -= 1;
        }
        stack.push(element);
    });
    /**
     *  k 개의 숫자를 제거했다면 stack은 그대로 두고 
     *  number.length - k 만큼 반환하기
     *  k가 남아있는 경우에는 뒤에서 제거
     *  ex) [1,9,2,2], 2 -> 92
     */
    stack.splice(stack.length - k, k);

    return stack.join('');
}

console.log(solution('4177252841', 4));
// console.log(solution('1231234', 3));
// console.log(solution('1924', 2));