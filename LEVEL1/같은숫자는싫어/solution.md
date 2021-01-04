# SOLUTION

unique 라는 함수를 사용할 경우
→ 자주 사용하기는 어려울 것으로 생각
```c++
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{

    arr.erase(unique(arr.begin(), arr.end()),arr.end());

    vector<int> answer = arr;
    return answer;
}
```
아래 답안이 가장 현실적인 것 같다.

```c++
for(int i =0; i<arr.size();i++) {
        if(answer.empty()) answer.push_back(arr[i]);
        else{
            if(answer.back()!=arr[i]) answer.push_back(arr[i]);
        }
    }
```

풀이(main.cpp)에서 stack을 사용했는데, 굳이 사용하는 것이 아닌가 생각<br>
단순히 입력하기 전에 있는 수를 확인만 하면 되는 것이라 vector를 스택(stack)처럼 사용할 수 있다는 점<br>
