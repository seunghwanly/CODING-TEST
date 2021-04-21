#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N, M, answer = 0;
vector<vector<int>> map;
// right left down top
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct pos
{
    int y, x, time;
};

bool visited[101][101] = {
    false,
};

void BFS()
{
    queue<pos> q;
    q.push({1, 1, 1});
    visited[1][1] = true;

    while (!q.empty())
    {
        pos front = q.front();
        answer = front.time;
        q.pop();

        if (front.x == M && front.y == N)
            break;

        // check nearby
        for (int i = 0; i < 4; i++)
        {
            int nextX = front.x + dx[i];
            int nextY = front.y + dy[i];

            if (nextX < 1 || nextX > M || nextY < 1 || nextY > N)
                continue;
            if (map[nextY][nextX] == 1 && !visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                q.push({nextY, nextX, answer + 1});
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    map.resize(N + 1);
    // input lines
    string input;
    string line;
    int cnt = 0;
    while (getline(cin, line))
    {
        input += line;
        cnt++;
        if (cnt > N)
            break;
    }
    for (int i = 0; i < N; ++i)
    {
        map[i + 1].push_back(-1);
        for (int j = 0; j < M; ++j)
        {
            map[i + 1].push_back(input[i * M + j] - '0');
        }
    }
    
    BFS();
    cout << answer << "\n";

    return 0;
}