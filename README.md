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