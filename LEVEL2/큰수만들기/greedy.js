function greedy(arr, size) {
    // save results
    let candidateSet = [];
    /**
     *  2의 arr.length승 만큼 연산
     *  부분 집합의 갯수 만큼 연산
     *  TODO: 연산횟수를 줄여야함
     */
    for (let i = 0; i < Math.pow(2, arr.length); i++) {
        // temp array
        let temp = [];
        let len = arr.length - 1;
        // do while 문을 이용해서 len이 0이 될때까지 반복
        do {
            /**
             *  비트연산자 이용, i << len은
             *  00000000000000000000000000000001 를 len만큼 left shift(<<)
             * 
             *  arr = [1,9,2,4] 
             * 
             *  예를 들어서 i가 0이고 len이 3일때 left shift(<<)한 결과는
             *  00000000000000000000000000101000 : 40
             *  이때 i & (1 << len) 의 값은
             *      00000000000000000000000000000000
             *      00000000000000000000000000101000
             *  &------------------------------------
             *      00000000000000000000000000000000    : 0 -> push 하지 않는다.
             *  
             *  예를 들어서 i가 3이고 len의 값은 1일 때 & 연산을 하게되면
             *      00000000000000000000000000000011    : i
             *      00000000000000000000000000000010    : (1 << len)
             *  &------------------------------------
             *      00000000000000000000000000000010    : 2 -> push(9)
             */
            if ((i & (1 << len)) !== 0) {
                temp.push(arr[len]);
            }
        } while (len--);
        // 설정한 size와 temp의 값이 같아질 경우 후보자로 push
        if (temp.length === size) {
            candidateSet.push(temp);
        }
    }

    return candidateSet;
}

console.log(greedy([1, 9, 2, 4], 2))
