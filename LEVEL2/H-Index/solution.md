# SOLUTION
### SOURCE CODE
```js
function solution(citations) {
     citations = citations.sort(sorting);
     var i = 0;
     while(i + 1 <= citations[i]){
         i++;
     }
     return i;


     function sorting(a, b){
         return b - a;
     }
}
```
> 최민아 , - , 장동혁 , Hoyoung Jung 외 18 명
---
코드 풀이를 하자면, 먼저 입력받은 배열을 큰 수가 앞에 오게끔 정렬을 해준다.

그 다음에 0부터 각 배열의 원소들과 비교를 해주는데 방식이 독특하다고 해야할까 내가 이해를 못한 것일까.

내가 문제를 잘못이해한 것 같다. 

풀이에서는 입력받은 배열을 내림차순으로 정렬을 해서 가장 큰 수 부터 비교를 해주는 데 다음과 같이 비교가 이루어진다.

#### 예시) [10, 11, 12, 13]
```
citations[i]    13  12  11  10
i               0++ 1++ 2++ 3++
```
그래서 답은 4가 반환이 된다.

굉장히 코드가 간결하고 앞서 작성한 내 코드는 그저 문제의 지문을 그대로 옮겨놓은 듯한 코드이다. 종이에 연습을 하고 구현에 들어가는 습관을 들여야 겠다.

<p align='end'><em>2021/03/30 H-Index</em></p>