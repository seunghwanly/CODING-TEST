# SOLUTION

```c++
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    int student[35];
    int answer = 0;

    for(int i : reserve) student[i] += 1;
    for(int i : lost) student[i] += -1;
    for(int i = 1; i <= n; i++) {
        if(student[i] == -1) {
            if(student[i-1] == 1) 
                student[i-1] = student[i] = 0;
            else if(student[i+1] == 1) 
                student[i] = student[i+1] = 0;
        }
    }

    for(int i  = 1; i <=n; i++)
        if(student[i] != -1) answer++;

    return answer;
}
```

## main.cpp 
- 여벌옷을 가져온 학생이 도난당했을 경우
    - 다른 학생에게 빌려줄 수 없게되므로 lost와 reserve에서 모두 제외를 해주었다. 
- lost 배열안에 있는 학생들을 기준으로 reserve 배열안에 있는 학생들을 검사
    - lost 원소 값의 -1 과 +1을 비교해서 reserve안에 있을 경우, 모두 0으로 초기화해주었다. 
    - 앞 원소부터 시작하므로 앞에 있는 학생일 수 록 빌려받을 확률이 높아지는 방법
- 시간복잡도는 <em><b>O(n^2)</b></em>

## SOLUTION.cpp
- 모든 학생에 대한 배열을 추가 : student[35];
- reserve 안에 있는 학생들은 student 배열안에서 +1
- lost 안에 있는 학생들은 -1
- 입력받은 n 명의 학생 수 만큼 for loop
    - 만약 student가 -1 이라면 student 앞 / 뒤 를 확인
        - 이때, student는 1부터 시작
    - 빌려준 경우 / 받은 경우 0으로 초기화

### :bulb: 만약, lost 한 학생이 3이고, reserve한 학생이 2, 4일 때는 if문과 else if 모두 0으로 초기화되는 경우
- 첫 번째 if문을 만족해서 2번째 3번째 학생이 모두 0으로 초기화
- 두 번째 else if문도 만족을 하기 때문에 3번째, 4번째 학생 모두 0으로 초기화
- 만약 lost 한 학생이 5가 또 있었다면 5번째 학생은 4가 빌려줄 수 있음에도 불구하고 빌려받지 못함

→ 조건문이 더 필요하지 않을 까 생각.

:smile: 장점은 시간복잡도가  <em><b>O(n)</b></em>
