#include <iostream>
#include <queue>

using namespace std;

int N, K, T, cnt = 0, sec;
bool visit[200001];

typedef struct
{
    int now, time;

} pos;

int main(void)
{
    cin >> N >> K;

    pos start = {N, 0};
    queue<pos> Q;
    Q.push(start);

    while (!Q.empty())
    {

        int now = Q.front().now;
        int time = Q.front().time;

        Q.pop();

        visit[now] = true;

        if (cnt && now == K && T == time)
        {
            cnt++;
        }

        if (!cnt && now == K)
        {
            T = time;
            cnt++;
        }

        if (now + 1 <= 200000 && !visit[now + 1])
        {
            pos temp = {now + 1, time + 1};
            Q.push(temp);
        }
        if (2 * now <= 200000 && !visit[2 * now])
        {
            pos temp = {2 * now, time + 1};
            Q.push(temp);
        }
        if (now - 1 >= 0 && !visit[now - 1])
        {
            pos temp = {now - 1, time + 1};
            Q.push(temp);
        }
    }
    cout << T << "\n"
         << cnt;

    return 0;
}
