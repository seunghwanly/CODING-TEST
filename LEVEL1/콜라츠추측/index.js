function solution(num) {

    const getCount = (input, cnt) => {
        if (input === 1) return cnt;
        else {
            if (cnt > 500) return -1;
            if (input % 2 === 0) return getCount((input / 2), cnt + 1);
            else return getCount((input * 3) + 1, cnt + 1);
        }
    }

    return getCount(num, 0);
}

console.log(solution(6));
console.log(solution(16));
// console.log(solution(626331));