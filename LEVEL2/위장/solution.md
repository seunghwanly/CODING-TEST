# SOLUTION

처음에 문제를 접근할 때 조합으로 문제를 해결하려고 했는데, 알고있는 테스트 케이스들은 통과를 했지만 작성한 소스코드로 프로그래머스에서 제출을 해봤을 때 36.1 / 100 점을 맞았다. 나름 수학적으로 접근을 한 듯 보였는데 질문하기에서 테스트 케이스를 더 추가해서 돌려봐도 테스트케이스는 잘 되고 이유를 못찾고 있다가 [스포주의]를 보고 다시 생각해보았다.

### 처음에 작성한 소스코드
```js
function solution(clothes) {
    var answer = 0;

    let map = [];

    // [ name, kind ] to map
    clothes.forEach(element => {
        let name = element[0];
        let kind = element[1];

        let index = map.findIndex((value, index) => value.kind === kind);
        if (index === -1) {
            map.push(
                {
                    'kind': kind,
                    'names': [name]
                }
            );
        } else {
            map[index].names.push(name);
        }
    });

    const calculateCombination = (n, k) => {
        let molecule = 1;
        for (let i = 0; i < k; ++i) {
            molecule *= (n - i);
        }
        let denominator = 1;
        for (let i = k; i >= 1; --i) {
            denominator *= i;
        }
        return Math.floor(molecule / denominator);
    }

    /**
     *  N개의 집단, K개씩 뽑기(1, ..., N)
     *  K가 1일 경우 모든 갯수
     *  K가 1이 아닐 경우 
     *      n C k - SUM( 각 배열의 길이 C k)
     */
    let n = 0;
    map.forEach((element) => { n += element.names.length });

    for (let i = 1; i <= map.length; ++i) {
        if (i === 1) {
            // add all length
            answer += n;
        }
        else {
            let sumofArrays = 0;
            map.forEach((element) => {
                if (element.names.length >= i) {
                    // 한 집단에서 k개를 모두 뽑을 경우
                    sumofArrays += calculateCombination(element.names.length, i);
                    // 한 집단에서 (k-1)개를 모두 뽑을 경우
                    for(let k = i - 1; k > 1; --k) {
                        sumofArrays += calculateCombination(element.names.length, k) * (n - element.names.length);
                    }
                }
            })
            answer += (calculateCombination(n, i) - sumofArrays);
        }
    }

    return answer;
}
```

#### 풀이방법
map에는 m개의 집단이 있다고 가정하고 각 집단의 길이는 다르다. 이때 모든 집단의 원소 갯수를 더한 값, 즉 모든 의상의 갯수를 n이라고 하고 k개씩 뽑는다고 가정을 해보았다.


    k = 1일 때       n가지
    k = 2일 때       n Comb 2 - n Comb 1 
    
    k = l 일때       n Comb l - SUM{ n Comb (l - i) * ( n - 각 집단의 길이 ) }, i는 l부터 2까지

이렇게 실행해보았을 때 테스트케이스는 모두 통과를 할 수 있었다.

### 새로운 풀이방법

문제를 다시 보면 각 집단에서 오로지 0개 또는 1개를 선택해야하는 문제이다. 예를 들어서 map이
```js
[
    {
        '종류' : '가',
        '이름' : [ 'a', 'b', 'c' ]
    },
    {
        '종류' : '나',
        '이름' : [ 'aa', 'bb', 'cc' ]
    },
    {
        '종류' : '다',
        '이름' : [ 'aaa', 'bbb', 'ccc' ]
    },
]
```
이렇게 되어 있을 때, '가' 집단에서 0개 또는 1개를 뽑을 수 있는 경우의 수는 `'a', 'b', 'c', ' '` 총 4가지이다. 마찬가지로 '나' 집단과 '다'집단에서 뽑을 수 있는 경우의 수는 각각 4가지이다. 4가지를 모두 곱해주면 64가지가 되는데, 이때 3개의 집단에서 아무것도 뽑지 않았을 경우를 빼줘야한다. 최종적으로 답은 `64 - 1 = 63`가 된다. 소스 코드는 아래와 같다.

#### 소스코드
```js
function solution(clothes) {
    let map = [];
    // [ name, kind ] to map
    clothes.forEach(element => {
        let name = element[0];
        let kind = element[1];

        let index = map.findIndex((value, index) => value.kind === kind);
        if (index === -1) {
            map.push(
                {
                    'kind': kind,
                    'names': [name]
                }
            );
        } else {
            map[index].names.push(name);
        }
    });

    let res = 1;
    map.forEach(e => res *= (e.names.length + 1));
    return res - 1;
}
```

상황을 더 단순하게 생각했다면 쉽게 접근했을텐데 그러지 못한 게 아쉽다. 문제를 더 어렵게 푼 거 같기도하고, 문제를 문제 그대로 풀어버린 거 같다. 

#### 사용한 테스트케이스
```js
console.log(solution([["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]])); // 5
console.log(solution([["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]])); // 3

console.log(solution([
    ["a", "aa"],
    ["b", "aa"],
    ["c", "aa"],
    ["aa", "bb"],
    ["bb", "bb"],
    ["c_c", "bb"],
    ["aaa", "cc"],
    ["bbb", "cc"],
    ["ccc", "cc"]
]));    // 63
console.log(solution([
    ["a", "a"],
    ["b", "b"],
    ["c", "c"]
])); // 7
```