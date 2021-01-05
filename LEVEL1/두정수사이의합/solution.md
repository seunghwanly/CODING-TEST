# SOLUTION

```c++
#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    if (a > b) a ^= b ^= a ^= b;
    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
    return answer;
}
```

## 비트연산자 ^(XOR)의 사용
예시) a : 5, b : 3
```terminal
a : 0101 (5)    a = 6;  b : 0011 (3)    b = 5;   a : 0110 (6)       ✔︎ a = 3;
b : 0011 (3)            a : 0110 (6)             b : 0101 (5)       ✔︎ b = 5;
→   0110 :6             →   0101 :5              →   0011 :3
```
비트연산을 이용해서 두 수의 대소를 구분지을 수 있다.
## 비트연산 ~(NOT)의 사용 및 부호비트
```terminal
  b  : 0101 (5)           a : 0011 (3)
 ~b  : 1010 (-6)         -a : 1101 (-3)
-~b  : 0010 (6)         ~-a : 0010 (2)
```
계산 결과를 확인하면 answer에는 5 * 3 - 3 * 1 = 12가 저장된다.