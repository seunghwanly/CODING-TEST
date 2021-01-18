# SOLUTION

2중 for문을 이용하지 않고도 공백을 기준으로 count을 초기화 해준다면 시간복잡도를 줄일 수 있다. 

```js
function solution(s) {
    let answer = '';
    let count = 0;
    for(let i=0; i<=s.length; ++i) {
        if(count % 2 === 0) { answer += s[i].toUpperCase(); count++; }
        else if (count % 2 === 1) { answer += s[i].toLowerCase(); count++; }
        else count = 0;
    }

    return answer;
} 
```