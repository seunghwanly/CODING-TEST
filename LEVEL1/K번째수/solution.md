# SOLUTION
```c++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}
```

## 내가 작성한 코드와의 차이
<ol>
<li>변수를 최소화</li>
    <ol>array를 모두 temp에 복사를 해서 바로 temp로 나머지 작업을 진행
    </ol>
    <ol>
    i, j, k 와 같은 변수를 사용하지 않고 바로 answer에 push_back
    </ol>
<li>temp의 선언</li>
<ol>temp를 for문 안에서 선언하지 않고 바깥 블록에서 선언</ol>
</ol>