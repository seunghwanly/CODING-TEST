#include <iostream>
#include <queue>

using namespace std;

int N, K, T;
bool visit[200001];

typedef struct
{
    int now, time;

} pos;

int main(void)
{
    cin >> N >> K;
    if (K < N)
    {
        cout << N - K;
    }
    else if (N == K)
    {
        cout << 0;
    }
    else
    {

        pos start = {N, 0};
        queue<pos> Q;
        Q.push(start);
        int now = N;
        while (!Q.empty())
        {

            now = Q.front().now;
            T = Q.front().time;
            if (now == K)
                break;
            Q.pop();

            if (now + 1 <= 200000 && !visit[now + 1])
            {
                visit[now + 1] = true;
                pos temp = {now + 1, T + 1};
                Q.push(temp);
            }
            if (2 * now <= 200000 && !visit[2 * now])
            {
                pos temp = {2 * now, T + 1};
                visit[2 * now] = true;
                Q.push(temp);
            }
            if (now - 1 >= 0 && !visit[now - 1])
            {
                pos temp = {now - 1, T + 1};
                visit[now - 1] = true;
                Q.push(temp);
            }
        }
        cout << T;
    }

    return 0;
}
