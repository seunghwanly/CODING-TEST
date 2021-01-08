# SOLUTION

```c++
#include <string>
#include <vector>
using namespace std;

bool solution(string s) {
    bool answer = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
            answer = false;
    }

    return s.size() == 4 || s.size() == 6 ? answer : false;
}
```

### isdigit( ) 함수
```
ASCII CODE 표에서 48번째부터 57번째까지 '0','1', ... , '9'까지 인식이 되면 True 가 반환되는 함수이다. 
```