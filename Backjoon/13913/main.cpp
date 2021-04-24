#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K, T;
vector<int> P;
int visited[200001] = {
    false,
};

struct pos
{
    int x, time;
    vector<int> path;
};

void BFS()
{
    queue<pos> q;
    visited[N] = true;
    P.push_back(N);
    q.push({N, 0, P});

    while (!q.empty())
    {
        pos front = q.front();
        q.pop();

        T = front.time;
        int curr = front.x;
        P = front.path;

        if (front.x == K)
            break;

        // 2x
        if (curr * 2 < 100001 && !visited[curr * 2])
        {
            visited[curr * 2] = true;
            P.push_back(curr * 2);
            q.push({curr * 2, T + 1, P});
            P.pop_back();
        }
        // x -1
        if (curr - 1 >= 0 && !visited[curr - 1])
        {
            visited[curr - 1] = true;
            P.push_back(curr - 1);
            q.push({curr - 1, T + 1, P});
            P.pop_back();
        }
        // x + 1
        if (curr + 1 < 100001 && !visited[curr + 1])
        {
            visited[curr + 1] = true;
            P.push_back(curr + 1);
            q.push({curr + 1, T + 1, P});
            P.pop_back();
        }
    }
}

int main()
{
    cin >> N >> K;
    /**
     * @brief vector를 통해서 path를 저장할 경우에는 저장할 원소의 갯수가 매우 커지게된다.
     * 예를 들어서 100,000 에서 0으로 갈 때는 
     * 100,000  : 1
     * 99,999   : 2
     * 99,998   : 3
     * ...
     * 0        : 100,001
     * 모두 합하면 약 50억개의 원소가 vector안에 저장되어야한다.
     * >> 시간초과 해결
     */
    if (K < N)
    {
        cout << N - K << "\n";
        for (int i = N; i >= K; --i)
        {
            cout << i << " ";
        }
    }
    else
    {
        BFS();
        cout << T << "\n";
        for (int i = 0; i < P.size(); ++i)
        {
            cout << P[i] << " ";
        }
    }
    return 0;
}