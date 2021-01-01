# SOLUTION

```c++
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for(int i=0;i<moves.size();i++)
    {
        int check = moves[i] - 1;
        for(int j=0;j<board.size();j++)
        {
            if(board[j][check] != 0)
            {
                if(!s.empty() && s.top() == board[j][check])
                {
                    s.pop();
                    answer += 2;
                }
                else
                    s.push(board[j][check]);
                board[j][check] = 0;
                break;
            }
        }
    }
    return answer;
}
```

* stack 을 사용해서 아래와 같이 조회하지 않아도 됨.
```c++
basket[basket.size() - 1] == basket[basket.size() - 2]
```
* 바구니에 담길 스택의 size를 empty로 설정하고 s의 top이랑 만 비교
* 문제풀이에는 먼저 바구니에 넣고 비교를 했다면, solution에서는 바구니에 넣기 전에 비교를 먼저 해주고 진행
