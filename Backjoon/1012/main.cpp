#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int T, M, N, K;

struct pos
{
    int y, x;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct map
{
    int map[50][50] = {
        0,
    };
};
struct visit
{
    bool visited[50][50] = {
        false,
    };
};

void DFS(int map[][50], bool visited[][50], pos P)
{
    if (map[P.y][P.x] == 1)
    {
        map[P.y][P.x] = 0;
        for (int i = 0; i < 4; ++i)
        {
            int nextY = P.y + dy[i];
            int nextX = P.x + dx[i];

            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M && !visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                DFS(map, visited, {nextY, nextX});
            }
        }
    }
}

int main()
{
    vector<map> maps = vector<map>();
    vector<visit> visits = vector<visit>();

    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        map m;
        visit v;
        // M N K
        cin >> M >> N >> K;

        for (int j = 0; j < K; ++j)
        {
            pos input;
            cin >> input.x >> input.y;
            m.map[input.y][input.x] = 1;
        }

        maps.push_back(m);
        visits.push_back(v);
    }

    for (int i = 0; i < T; ++i)
    {
        int count = 0;
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                if (maps[i].map[j][k] == 1)
                {
                    DFS(maps[i].map, visits[i].visited, {j, k});
                    count++;
                }
            }
        }
        cout << count << "\n";
    }

    return 0;
}