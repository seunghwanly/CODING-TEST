#include <iostream>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

int N, M, P;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int map[1000][1000] = {
    0,
};
bool visited[1000][1000] = {
    false,
};

bool canBreak = true;

struct pos
{
    int y, x, path;

};

bool inRange(pos p)
{
    return p.y >= 0 && p.y < N && p.x >= 0 && p.x < M;
}

bool isSurrounded(pos p)
{
    bool res = true;
    for (int i = 0; i < 4; ++i)
    {
        int ny = p.y + dy[i];
        int nx = p.x + dx[i];
        if (inRange({ny, nx}))
        {
            if (map[ny][nx] != 1)
                res = false;
        }
    }
    return res;
}

pos BFS(pos start, pos mid)
{
    pos finalState;
    queue<pos> q;
    q.push({start.y, start.x, start.path});
    visited[start.y][start.x] = true;

    while (!q.empty())
    {
        pos front = q.front();
        q.pop();

        P = front.path;
        if (front.y == mid.y && front.x == mid.x)
        {
            finalState = front;
            break;
        }

        for (int i = 0; i < 4; ++i)
        {
            int ny = front.y + dy[i];
            int nx = front.x + dx[i];
            if (inRange({ny, nx}) && !visited[ny][nx] && map[ny][nx] == 0)
            {
                visited[ny][nx] = true;
                q.push({ny, nx, P + 1});
            }
        }
    }
    return finalState;
}

int main()
{
    cin >> N >> M;
    // input
    int cnt = 0;
    string input, line;
    while (getline(cin, line))
    {
        input += line;
        cnt++;
        if (cnt > N)
            break;
    }
    // init map
    for (int i = 0; i < input.length(); ++i)
    {
        map[int(i / M)][int(i % M)] = input[i] - '0';
    }

    queue<pos> checkPoint;
    if (isSurrounded({0, 0}))
        checkPoint.push({0, 0});
    if (isSurrounded({N - 1, M - 1}))
        checkPoint.push({N - 1, M - 1});

    if (checkPoint.size() == 2)
        cout << -1;
    else if (checkPoint.size() == 1)
    {
        pos needBreak = checkPoint.front();
        // for start
        for (int k = 0; k < 4; ++k)
        {
            int ny2 = needBreak.y + 2 * dy[k];
            int nx2 = needBreak.x + 2 * dx[k];
            int ny = needBreak.y + dy[k];
            int nx = needBreak.x + dx[k];

            if (inRange({ny2, nx2}) && inRange({ny, nx}))
            {
                if (map[ny2][nx2] == 0 && map[ny][nx] == 1)
                {
                    if (canBreak)
                    {
                        canBreak = false;
                        map[ny][nx] = 0;
                        break;
                    }
                }
            }
        }
        // BFS
        pos finalPos = BFS({0, 0, 0}, {int(N / 2), int(M / 2), 0});
        // check in path

        if (canBreak)
        {
            P += abs((finalPos.y - N - 1) + (finalPos.x - M - 1)) - 1;
        }
        cout << P + 1; // 도착점까지 count
    }
    else
    {
        // go through
        pos finalPos = BFS({0, 0, 0}, {int(N / 2), int(M / 2), 0});
        if (canBreak)
        {
            P += abs((finalPos.y - N - 1) + (finalPos.x - M - 1)) - 1;
        }
        cout << P + 1; // 도착점까지 count
    }

    return 0;
}