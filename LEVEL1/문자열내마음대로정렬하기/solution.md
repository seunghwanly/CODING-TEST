# SOLUTION

```c++
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int i;

bool compare (string a, string b) {
    return a[i] == b[i] ? a < b : a[i] < b[i];
}

vector<string> solution(vector<string> strings, int n) {
    i = n;
    sort (strings.begin(), strings.end(), compare);
    return strings;
}
```

if문을 두 번 사용하지 않고 삼항연산자를 이용해서 코드를 더 간단하게 작성할 수 있는 답안이다.<br>
compare 함수를 만들어서 sort( )에 매개변수로 사용.