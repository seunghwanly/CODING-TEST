#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int map[1001][1001] = {
    0,
};

int M, N; // M columns, N rows

int answer = 0;

struct pos
{
    int y, x, time;
};

queue<pos> q;

/**
 * @brief tomato status
 * 
 * @param 1 = riped / 0 = not riped / -1 = none
 */

int BFS()
{
    int time = 0;

    while (!q.empty())
    {
        pos front = q.front();
        q.pop();

        time = front.time;

        for (int i = 0; i < 4; ++i)
        {
            int nextY = front.y + dy[i];
            int nextX = front.x + dx[i];

            if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N)
            {
                if (map[nextY][nextX] == 0)
                {
                    map[nextY][nextX] = 1;
                    q.push({nextY, nextX, time + 1});
                }
            }
        }
    }
    return time;
}

int main()
{

    cin >> M >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }

    answer += BFS();

    // check there is 0 in map
    int check = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == 0)
            {
                check++;
            }
        }
    }
    if (check != 0)
        cout << -1;
    else
        cout << answer;

    return 0;
}
