# SOLUTION

> - , minho.choi , rocks 님의 풀이

```js
function solution(n) {
    // 문자풀이
    // return (n+"").split("").reverse().map(v => parseInt(v));

    // 숫자풀이
    var arr = [];

    do {
        arr.push(n%10);
        n = Math.floor(n/10);
    } while (n>0);

    return arr;
}
```

하나의 자연수를 10으로 나눈 나머지 즉, 한자리의 나머지를 계속 배열에 추가를 해주면서 n을 10으로 나누어준다. 
