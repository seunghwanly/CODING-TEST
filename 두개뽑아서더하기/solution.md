# SOLUTION

```c++
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> st;
    for(int i = 0;i<numbers.size();++i){
        for(int j = i+1 ; j< numbers.size();++j){
            st.insert(numbers[i] + numbers[j]);
        }
    }
    answer.assign(st.begin(), st.end());
    return answer;
}
```

* set 의 사용
* set안에 정렬과 삽입을 동시에 진행 → 간결한 코드 완성
* set가 완성되면 완성된 set를 그대로 answer에 할당