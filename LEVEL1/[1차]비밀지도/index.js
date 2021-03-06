function solution(n, arr1, arr2) {
    // 0 * 0 = 0 | 1 * 0 = 1 | 0 * 1 = 1 | 1 * 1 = 1
    let map = [];
    // hint
    let f_hint = arr1.map((e) => toBinary(e, n));
    let s_hint = arr2.map((e) => toBinary(e, n));

    // operate
    for (let i = 0; i < f_hint.length; ++i) {
        map.push(operate(f_hint[i], s_hint[i]));
    }

    return map;
}

const operate = (a, b) => {
    let res = '';
    for (let i = 0; i < a.length; ++i) {
        if (a[i] === '0' && b[i] === '0') res += ' ';
        else res += '#';
    }
    return res;
}

const toBinary = (num, n) => {
    let bin = num.toString(2);
    if (bin.length < n) {
        bin = '0'.repeat(n - bin.length) + bin;
    }
    return bin;
}

console.log(solution(5, [9, 20, 28, 18, 11], [30, 1, 21, 17, 28]));