# SOLUTION

다른 답안과 별 차이점이 없어서 제 답안을 공유합니다.

```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;

    for (auto a : arr)
    {
        if (a % divisor == 0)
        {
            answer.push_back(a);
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0)
        answer.push_back(-1);

    return answer;
}
```