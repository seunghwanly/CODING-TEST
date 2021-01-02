# SOLUTION

```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{

    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < participant.size(); ++i)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }
    }

    return answer;
}
```
## sort를 이용해 평균시간복잡도를 최소화
- sort함수는 <em><b>퀵 정렬(quick sort)</b></em>를 기반으로 구현
- 평균시간복잡도는 <em><b>nlogn</b></em>
<br/><br/>
<div style="border : 1px solid gray"> </div>
<br/><br/>

### 예시 1)
```c++
vector<string> participant = {"filipa", "josipa", "marina", "nikola", "vinko"};
vector<string> completion = {"filipa", "josipa", "marina", "nikola"};
```
    위와같이 정렬이 되면 순서대로 participant와 completion을 비교해줄 때 다른 값은 오직 하나만이 남게 된다. 여기서는 vinko를 제외한 모든 경우가 index와 value가 같기 때문에 완주를 못한 사람은 vinko가 되게 된다. 

### 예시 2)
```c++
vector<string> participant = {"josipa", "josipa", "marina", "nikola"};
vector<string> completion = {"josipa", "marina", "nikola"};
```
    위와 같은 경우는 동명이인이 있을 경우이다. josipa라는 사람이 두 명 참가했을 때 완주한 사람은 한 명의 josipa이다. 이럴 경우에는
                    participant[i] != completion[i]
    인 값을 찾아서 해당되는 i의 participant는 완주를 못한 참가자가 된다.
    