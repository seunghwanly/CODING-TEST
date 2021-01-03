# SOLUTION

```c++
#include <string>

using namespace std;

string solution(string s) {
    return s.length()&1 ? s.substr(s.length()*0.5,1) : s.substr(s.length()*0.5-1,2);
}
```
## 비트 AND 연산자의 이용
```c++
s.length() & 1
```
비트 연산을 이용한 삼항 연산자를 사용<br>

### 예시
ex1) 3 & 1
```terminal
    0000 0011
    0000 0001
→   0000 0001 
```
ex1) 4 & 1
```terminal
    0000 0100
    0000 0001
→   0000 0000 
```

#### 홀수일 경우 true, 짝수일 경우 false를 이용
#### 나머지 출력은 substr( )이용
