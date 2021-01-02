# SOLUTION

```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }
    return answer;
}
```

## 내가 작성한 코드와 비교
<ol>
    <li><a href="### <b>max element</b> 검색의 차이"><b>max element</b> 검색의 차이</a></li>
    <li><a href="### 정적배열과 동적배열">정적 배열, 동적 배열</a></li>
</ol>

### <b>max element</b> 검색의 차이
- \<algorithm> 헤더 안에 있는 max_element의 사용, 코드가 간결해짐

### 정적배열과 동적배열
- 위에 A,B,C 가 모두 정적인 배열이기 때문에 만약 문제에서 패턴을 동적으로 입력받는 다면 매번 수정을 해주어야할 것이다. 
- SOLUTION에서는 간단하게 they라는 동적배열 하나로 사용하였고, 내가 작성한 코드에는 불필요하게 int 변수를 3개와 정적배열하나, 변수를 간단하게 사용하지 못했다. 
