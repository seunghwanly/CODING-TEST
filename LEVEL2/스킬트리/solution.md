# SOLUTION

이 문제를 풀면서 생각보다 많은 for문을 사용하게 되었다.<br>
먼저 주어진 스킬트리에 대한 배열을 하나 만들어, 이를 입력되는 스킬트리와 비교하였다. <br>
예를 들어서, **"CBD"** 가 주어진 스킬트리이고 입력되는 스킬트리가 **"BACDE"** 이라고 하면 아래와 같다. <br>

```
CBD → 0 1 2 로 index를 지정
BACDE를 검사하여 발견한 index를 새로운 배열에 저장
→ 1 0 2 순으로 저장됨
```

오직 0, 1, 2 ... 순으로 index에 대한 배열에 저장이 되야 하므로 저장된 원소값과 인덱스값을 비교해서 결과를 검사하였다.<br>
이와 같이 풀게 되면 주어진 스킬트리에 대한 for문, 입력받은 스킬트리들에 대한 for문, 각 스킬트리 길이만큼의 for문 등 사용되는 for문의 갯수가 4개에다가 2중 for문이여서 <em><b>시간복잡도가 크다.<b><em> <br>

-------------------------------------------------------------------------------

> - , - , 석금용 , rocks , taejin0527 의 풀이

```js
function solution(skill, skill_trees) {
    var answer = 0;
    var regex = new RegExp(`[^${skill}]`, 'g');

    return skill_trees
        .map((x) => x.replace(regex, ''))
        .filter((x) => {
            return skill.indexOf(x) === 0 || x === "";
        })
        .length
}
```
>> indexOf( )가 문자열에서 사용할 때 값이 존재하면 제일 처음 발견된 index를 반환하기때문에 filter와 사용되었다. 입력받은 각 skill_trees의 원소마다 regex로 선언한 것을 모두 blank 처리해주었다. 
>>> RegExp란 ? 
```js
RegExp(pattern, flags?);
```
→ flags
1. g : 문자열 전체를 확인
2. i : 문자열에서 대소문자를 구분하지않음
3. m : 문자열 내 '^', '$' 에서 개행문자 허용
4. s : 문자열 내 '.' 에서 개행문자 허용
5. y : lastIndex부터 일치하는 문자열 반환
6. u : UNICODE 포인트의 시퀀스로 처리

* 'g'를 사용하여 문자열 전체를 확인한다. 
* [^${skill}]은 주어진 스킬트리 순, 즉 패턴(pattern)이다. 

💡 skill_trees의 각 원소가 주어진 skill(= pattern)가 같은지 map과 filter를 사용해서 return