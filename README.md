<h1 align="center"> <a href="https://programmers.co.kr/learn/challenges">프로그래머스</a> 코딩테스트 준비기록 </h1>

### stack의 사용

```c++
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
    stack<int> s;

    // 데이터 입력
    s.push(저장할 데이터);
    // 데이터 삭제 (스택)
    s.pop();
    // top 접근
    s.top()
}
```
* stack(스택)을 이용해서 불필요하게 ~~vector\<int>~~ 을 사용할 필요가 없다.
* s.top()을 통해서 바로 top에 접근할 수 있다.

<p align='end' style='color:lightgrey'><em>
<a href="https://github.com/seunghwanly/CODING-TEST/blob/main/%ED%81%AC%EB%A0%88%EC%9D%B8%EC%9D%B8%ED%98%95%EB%BD%91%EA%B8%B0%EA%B2%8C%EC%9E%84/solution.md">
- 2021/01/01 크레인인형뽑기게임</a>
</em></p>

### set 의 사용
```c++
#include <set>

using namespace std;

// 생성자
set<int> s;
set<int> s(pred);   // pred를 통해 정렬기준을 설정

// set 멤버 함수
s.begin();
s.end();
s.rbegin(); s.rend();   // 역으로 작업할 때 
s.clear();
s.count(원소 값); // set에서는 무조건 0 이거나 1 : 중복X 이진트리 이기 때문
s.insert(원소 값);  // 자동으로 정렬해서 삽입되는 멤버 함수
...
```
* 연관 컨테이너(associative container) 중 하나
* <b>노드 기반 컨테이너</b>이며 "균형 이진트리"로 구현
* 원소들의 값은 <b>중복 허용 X</b>
* <b>insert</b> 멤버 함수에 의해서 자동으로 정렬.
* default 정렬 기준은 <b>오름차순</b>
* iterator가 자동으로 inorder traversal 순서대로 출력가능
<p align='center'>
<img src='https://user-images.githubusercontent.com/22142225/103436483-0be39380-4c5f-11eb-90b1-a315ad05c8bc.png
'/>
</p>
<p align='end' style='color:#eee'><em>
<a href="https://github.com/seunghwanly/CODING-TEST/blob/main/%EB%91%90%EA%B0%9C%EB%BD%91%EC%95%84%EC%84%9C%EB%8D%94%ED%95%98%EA%B8%B0/solution.md">
- 2021/01/01 두개뽑아서더하기</a></em></p>

### 시간복잡도를 줄이기
* <b>완주하지 못한 선수</b> 문제는 정확도 테스트는 통과했지만 효율성 테스트에서 통과하지못해서 코드를 수정했던 문제이다. 
* 기존 코드 시간복잡도 : O(n^2) | 수정한 코드 시간 복잡도 : O(nlogn)

```c++
#include <algorithm>

using namespace std;
...
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
...
```
### void sort(T start, T end)
- sort 알고리즘은 <em><b>퀵 정렬(quick sort)</b></em>를 기반으로 구현 
- 평균 시간복잡도는 <em><b>nlogn</b></em>

<p align='end' style='color:#eee'><em>
<a href="https://github.com/seunghwanly/CODING-TEST/blob/main/LEVEL1/%EC%99%84%EC%A3%BC%ED%95%98%EC%A7%80%EB%AA%BB%ED%95%9C%EC%84%A0%EC%88%98/solution.md">
- 2021/01/02 완주하지못한선수</a></em></p>

### javaScript : shift( )
* 배열에서 첫 번째 요소를 제거하고, 제거된 요소를 반환 → pop()
* 하나의 배열을 queue 처럼 사용할 수 있다는 장점
shift( )를 사용하게 되면 아래와 같이 사용할 수 있다. 
```js
array : [ 0, 1, 2, 3 ]
          ^
         top
```
array.shift();
```js
array : [ 1, 2, 3 ]
```
<p align='end' style='color:#eee'><em>
<a href="https://github.com/seunghwanly/CODING-TEST/blob/main/LEVEL2/%EB%8B%A4%EB%A6%AC%EB%A5%BC%EC%A7%80%EB%82%98%EB%8A%94%ED%8A%B8%EB%9F%AD/index.js">
- 2021/01/02 완주하지못한선수</a></em></p>

### 최대공약수
* 재귀함수를 이용한 함수 생성
```js
    const getGCD = (a, b) => {
        if(b === 0) return a;
        else return getGCD(b, a%b);
    }   
```
b를 가지고 a를 나눈 나머지를 계속 구하게된다. 이때 b가 0이 되게되면 그전의 b가 최대공약수가 되기 때문에 a를 return
> 최소공배수는 두 수의 곱을 최대공약수로 나눈 값
- 2021/03/04 최대공약수와최소공배수

### reduce( )
reduce()는 빈 요소를 제외하고 배열 내에 존재하는 각 요소에 대해 callback 함수를 한 번씩 실행하는데, 콜백 함수는 다음의 네 인수를 받습니다:

* accumulator
* currentValue
* currentIndex
* array

예를 들어서
```js
array.reduce((a,b)=> a+b);
```
위와 같이 코드를 작성하게되면 모든 배열의 원소를 더한 값이 반환된다. 유용하게 쓰일 함수로 보인다. 
- 2021/03/04 평균구하기