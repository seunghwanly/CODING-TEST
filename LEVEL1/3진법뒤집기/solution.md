# SOLUTION

```c++
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while(n > 0){
        v.push_back(n%3);
        n/=3;
    }
    int k = 1;
    while(!v.empty()) {
        answer += k*v.back();
        v.pop_back();
        k*=3;
    }

    return answer;
}
```

~~~
factor를 구하고 모두 3진법 배열안에 넣는 것은 코드가 비효율적이다. 
→ 하나의 while 문으로 n%3 을 삽입하고 n /=3 해주는 것이 효율적 
~~~

* 첫 번째 while 문에서 n이 0보다 클 동안만 진행이 되기 때문에, n이 45일 경우에는 0 0 2 1 이렇게 순차적으로 v에 저장 된다. 
* 두 번째 while 문에서 v안에 저장했던 0 0 2 1 을 하나씩 pop( )시켜서 3의 1제곱 부터 v 배열에 아무것도 남지 않을 때 까지 진행한다. 

→ main.cpp 에서 사용한 것 처럼 reverse( )를 사용하지 않아도 된다는 장점이 있다. <br>
→ 첫 번째 while문 처럼 사용하는 것이 좋은 방법인 것 같다. (계산과정이 간단하다)<br>
