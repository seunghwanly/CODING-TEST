# SOLUTION

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    sort(s.rbegin(),s.rend());
    return s;
}
```

string도 vector의 멤버함수를 지원하기 때문에 rbegin()과 rend()를 사용하는 면이 더 간결한 코드를 작성할 수 있다.