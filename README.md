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

<p align='end' style='color:lightgrey'><em>- 2021/01/01 크레인인형뽑기게임</em></p>
